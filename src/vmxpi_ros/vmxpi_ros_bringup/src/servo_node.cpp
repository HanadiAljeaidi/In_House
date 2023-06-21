#include "TitanDriver_ros_wrapper.h"
#include "navX_ros_wrapper.h"
#include "Cobra_ros.h"
#include "Sharp_ros.h"
#include "Servo_ros.h"
#include "Ultrasonic_ros.h"
#include "IOwd_ros.h"
#include "DI_ros.h"
#include "DO_ros.h"
#include <unistd.h>
#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Twist.h"

#include <dynamic_reconfigure/server.h>
#include <vmxpi_ros_bringup/MotorSpeedConfig.h>
#include <vmxpi_ros/Float.h>
#include <cmath>

double servo_angle;
static double angle;
static double angle_t;


void servo_angle_callback(const std_msgs::Float32::ConstPtr& msg)
{
   servo_angle = msg->data;
   ROS_INFO("angle:  %f ", servo_angle);
}

void angleCallback(const std_msgs::Float32::ConstPtr& msg)
{
    angle = abs(msg->data);
}
void yawCallback(const std_msgs::Float32::ConstPtr& msg)
{
    angle_t = msg->data;
}

class ServoNode
{
   private:

   public:
   ros::ServiceClient resetAngle;
   vmxpi_ros::Float msg;
   ros::ServiceClient setAngle;
   ros::Subscriber servo_angle_sub;
   ros::Subscriber yawAngle_sub;
   ros::Subscriber angle_sub;

   ServoNode(ros::NodeHandle *nh){
      setAngle = nh->serviceClient<vmxpi_ros::Float>("channel/13/servo/set_angle"); // Using the set_angle service, channel index is declared in the constructor
      servo_angle_sub = nh->subscribe("channel/13/servo/angle", 1, servo_angle_callback);
      resetAngle = nh->serviceClient<std_srvs::Empty>("reset_navx");
      yawAngle_sub = nh->subscribe("navx/yaw", 1, yawCallback);
      angle_sub = nh->subscribe("navx/angle", 1, angleCallback);
    }

    void setServoAngle()
    {
      ros::Rate loop_rate(1);
      reset();
      vmxpi_ros::Float msg;
      while (ros::ok())
      {
      //   ROS_INFO("I AM HERE!");
      //   angle = 45; //Range -150 - 150 angle
        msg.request.data = angle;
        setAngle.call(msg);
        ros::spinOnce();
        loop_rate.sleep();
      }
    }

     void reset()
    {
        std_srvs::Empty msg2;
        resetAngle.call(msg2); // Resets yaw variable
    }

};


int main(int argc, char **argv)
{
   system("/usr/local/frc/bin/frcKillRobot.sh"); 
   ros::init(argc, argv, "servo_node");

   ros::NodeHandle nh; //internal reference to the ROS node that the program will use to interact with the ROS system
   VMXPi vmx(true, (uint8_t)50); //realtime bool and the update rate to use for the VMXPi AHRS/IMU interface, default is 50hz within a valid range of 4-200Hz
   
   ros::AsyncSpinner spinner(4);
   spinner.start();

   ServoROS servo(&nh, &vmx, 13);
   navXROSWrapper navx(&nh, &vmx);

   // ros::ServiceClient setAngle;

   servo.GetAngle(); 
   servo.GetMinAngle(); 
   servo.GetMaxAngle(); 

   // setAngle = nh.serviceClient<vmxpi_ros::Float>("channel/13/servo/set_angle");
   // float angle=0;
   // while (ros::ok())
   //    {
   //      ROS_INFO("I AM HERE!");
   //      vmxpi_ros::Float msg;
   //      angle = 45; //Range -150 - 150 angle
   //      msg.request.data = angle;
   //      setAngle.call(msg);
   //    //   ROS_INFO("NOW HERE!");
   //    }
   ServoNode srvController(&nh);
   
   srvController.setServoAngle();

//    ros::ServiceClient setAngle;
//    ros::sSubscriber servo_angle_sub;

   //ros::spin(); //ros::spin() will enter a loop, pumping callbacks to obtain the latest sensor data
   ROS_INFO("ROS SHUTDOWN");
   ros::waitForShutdown();
   return 0; 

}
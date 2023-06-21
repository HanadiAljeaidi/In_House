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


double yawAngle;

// Returns the current yaw value (in degrees, from -180 to 180) reported by the NavX sensor
void angle_callback(const std_msgs::Float32::ConstPtr& msg)
{
   yawAngle = msg->data;
}

class NavxNode
{
   private:
   ros::Subscriber yawAngle_sub;

   public:
   NavxNode(ros::NodeHandle *nh)
   {
      yawAngle_sub = nh->subscribe("navx/yaw", 1, angle_callback);
   }

};

int main(int argc, char **argv)
{
   system("/usr/local/frc/bin/frcKillRobot.sh"); //Terminal call to kill the robot manager used for WPILib before running the executable.
   ros::init(argc, argv, "navx_node");

   /**
    * Constructor
    * NavX's ros threads (publishers and services) will run asynchronously in the background
    */
   ros::NodeHandle nh; //internal reference to the ROS node that the program will use to interact with the ROS system
   VMXPi vmx(true, (uint8_t)50); //realtime bool and the update rate to use for the VMXPi AHRS/IMU interface, default is 50hz within a valid range of 4-200Hz

   navXROSWrapper navx(&nh, &vmx);

   ros::spin(); //ros::spin() will enter a loop, pumping callbacks to obtain the latest sensor data

   return 0;
}
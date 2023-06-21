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

#include <std_msgs/Float32.h>
#include <vmxpi_ros/Float.h>
#include <cmath>



double sharp_dist;


void sharp_dist_callback(const std_msgs::Float32::ConstPtr& msg)
{
   sharp_dist = msg->data;
}



class SharpNode{
   private:
   ros::Subscriber sharpDist_sub;
   ros::Publisher sharp_dist_pub;
   // ros::ServiceServer update_rate;
   ros::ServiceClient update_rate_client;

   public:     
   SharpNode(ros::NodeHandle *nh)
   {
      sharp_dist_pub = nh->advertise<std_msgs::Float32>("channel/22/sharp_ir/dist", 1);
      sharpDist_sub = nh->subscribe("channel/22/sharp_ir/dist", 1,sharp_dist_callback);
      //ros::ServiceServer update_rate = nh.advertiseService("get_update_rate", &navXROSWrapper::GetUpdateRate);
      update_rate_client = nh->serviceClient<vmxpi_ros::IntRes>("get_update_rate");

      // update_rate = nh->advertiseService("get_update_rate", &navXROSWrapper::GetUpdateRate);
   }

   void publishMessage(){
      std_msgs::Float32 msg;
     // msg.data = GetIRDistance();
      sharp_dist_pub.publish(msg);
      
   }
   //navXROSWrapper::navXROSWrapper(ros::NodeHandle *nh, VMXPi *vmx)	
};

// bool navXROSWrapper::GetUpdateRate(vmxpi_ros::IntRes::Request &req, vmxpi_ros::IntRes::Response &res)
// {
//    res.data = ahrs->GetActualUpdateRate();
//    return true;
// }

int main(int argc, char **argv)
{
   system("/usr/local/frc/bin/frcKillRobot.sh"); //Terminal call to kill the robot manager used for WPILib before running the executable.
   ros::init(argc, argv, "main_node");
  
   ros::AsyncSpinner spinner(4); //Allows callbacks from multiple threads; spins asynchronously using 4 threads
   spinner.start(); //Starts this spinner spinning asynchronously
   
   ros::NodeHandle nh; //Internal reference to the ROS node that the program will use to interact with the ROS system
   VMXPi vmx(true, (uint8_t)50); //Realtime bool and the update rate to use for the VMXPi AHRS/IMU interface, default is 50hz within a valid range of 4-200Hz
    
   /**
    * START CODE HERE
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    * 
    */
    SharpROS sharp(&nh, &vmx,22);
    

    double distance = sharp.GetIRDistance();
    
     ros::Rate loop_rate(50);
     SharpNode publisher1(&nh);
     while(ros::ok()){
       publisher1.publishMessage();
     }
   
   //  navXROSWrapper navx(&nh, &vmx);

   //  loop_rate.sleep();
    ros::spin(); //can't use more than one spinner per file 
   
   ROS_INFO("ROS SHUTDOWN");
   ros::waitForShutdown();
   return 0;
}

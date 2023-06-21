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

#include <dynamic_reconfigure/server.h>
#include <vmxpi_ros_bringup/MotorSpeedConfig.h>
#include <std_msgs/Float32.h>
#include <vmxpi_ros/Float.h>
#include <cmath>


double ultrasonic_cm;

// Returns the distance value reported by the Ultrasonic Distance sensor
void ultrasonic_mm_callback(const std_msgs::Float32::ConstPtr& msg)
{
   ultrasonic_cm = msg->data;
   ROS_INFO("Distance from US sensor to object: %f mm. ", ultrasonic_cm * 10);
   
}

class UltrasonicNode
{
    private:
    ros::Subscriber ultrasonicCM_sub;
    
    public:
    UltrasonicNode(ros::NodeHandle *nh)
    {
      // Subscribing to Ultrasonic distance topic to access the distance data
        ultrasonicCM_sub = nh->subscribe("channel/9/ultrasonic/dist/cm", 1, ultrasonic_mm_callback); //This is subscribing to channel 9, which is the input channel set in the constructor
    }

};

int main(int argc, char **argv)
{
   system("/usr/local/frc/bin/frcKillRobot.sh"); //Terminal call to kill the robot manager used for WPILib before running the executable.
   ros::init(argc, argv, "ultrasonic_node");

   /**
    * Constructor
    * Ultrasonic's ros threads (publishers and services) will run asynchronously in the background
    */

   ros::NodeHandle nh; //internal reference to the ROS node that the program will use to interact with the ROS system
   VMXPi vmx(true, (uint8_t)50); //realtime bool and the update rate to use for the VMXPi AHRS/IMU interface, default is 50hz within a valid range of 4-200Hz


   UltrasonicNode us1(&nh);
   UltrasonicROS ultrasonic(&nh, &vmx, 8, 9); //channel_index_out(8), channel_index_in(9)
   ultrasonic.Ultrasonic(); //Sends an ultrasonic pulse for the ultrasonic object to read


   // Use these to directly access data
   uint32_t raw_distance = ultrasonic.GetRawValue(); // returns distance in microseconds
//    // or can use
   uint32_t cm_distance = ultrasonic.GetDistanceCM(raw_distance); //converts microsecond distance from GetRawValue() to CM
//    // or can use
//    uint32_t inch_distance = ultrasonic.GetDistanceIN(raw_distance); //converts microsecond distance from GetRawValue() to IN


   ros::spin(); //ros::spin() will enter a loop, pumping callbacks to obtain the latest sensor data

   return 0;
}
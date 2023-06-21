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


double sharp_dist;

// Returns the distance value reported by the Ultrasonic Distance sensor
void sharp_dist_callback(const std_msgs::Float32::ConstPtr& msg)
{
    sharp_dist = msg->data;
    ROS_INFO("Distance from IR sensor to object: %f mm" , sharp_dist * 10);
}


class SharpIRNode
{
    private:
    ros::Subscriber sharpDist_sub;

    public:
    SharpIRNode(ros::NodeHandle *nh)
    {
        sharpDist_sub = nh->subscribe("channel/22/sharp_ir/dist", 1, sharp_dist_callback);
    }
};

int main(int argc, char **argv)
{
    system("/usr/local/frc/bin/frcKillRobot.sh");
    ros::init(argc, argv, "sharp_node");

    ros::NodeHandle nh;

    VMXPi vmx(true, (uint8_t)50);

    SharpROS sharp(&nh, &vmx, 22);
    SharpIRNode sharp1(&nh);
    double dist_cm = sharp.GetIRDistance();
    double voltage = sharp.GetRawVoltage();

    ros::spin();

    return 0;

}
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


int main(int argc, char **argv)
{
    system ("usr/local/frc/bin/frcKillRobot.sh");
    ros::init(argc, argv, "digitalin_node");
    ros::NodeHandle nh;

    VMXPi vmx(true, (uint8_t)50);

    DigitalInputROS digital_in(&nh, &vmx, 22);

    digital_in.Get();

    ros::spin();

    return 0;

}
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


double motor1_speed;

void motor1_speed_callback(const std_msgs::Float32::ConstPtr& msg)
{
    motor1_speed = msg->data;
}

class TitanNode
{
    private:
    ros::Subscriber motor1_speed_sub;
     ros::ServiceClient set_m_speed;
     
    
    public: 
    TitanNode(ros::NodeHandle *nh){
        motor1_speed_sub = nh->subscribe("titan/motor1/speed", 1, motor1_speed_callback);
        set_m_speed = nh->serviceClient<vmxpi_ros::MotorSpeed>("titan/set_motor_speed");
    }

    void motor_control()
    {
        while(ros::ok())
        {
        vmxpi_ros::MotorSpeed msg;
        msg.request.speed = 1.0; 
        msg.request.motor = 0;
        set_m_speed.call(msg);
        }
    }

};


int main(int argc, char **argv)
{
    system("urc/local/frc/bin/frcKillRobot.sh");
    ros::init(argc, argv, "titan_node");
    ros::AsyncSpinner spinner(4);
    spinner.start();
    ros::NodeHandle nh;
    VMXPi vmx(true, (uint8_t)50);

    TitanDriverROSWrapper titan(&nh, &vmx);
    TitanNode s1(&nh);
    s1.motor_control();

    // vmxpi_ros::MotorSpeed msg;


    // ros::ServiceClient set_m_speed;
    // set_m_speed = nh.serviceClient<vmxpi_ros::MotorSpeed>("titan/set_motor_speed");

    // msg.request.speed = 1.0; 
    // msg.request.motor = 0;
    // set_m_speed.call(msg);



    return 0;
}
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
#include <cmath>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>


static double rightSpeed;
// static double right_encoder;
static double motor0_speed;
double motor_controller;
static double right_count;


void motor0_speed_callback(const std_msgs::Float32::ConstPtr& msg)
{
    motor0_speed = msg->data;
}

void  teleoperated_callback(const geometry_msgs::Twist::ConstPtr& msg)
{
   motor_controller = msg->linear.x; 
}

// void motor0_callback(const std_msgs::Float32::ConstPtr& msg)
// {
//     right_encoder = msg->data;
// }

void enc0_callback(const std_msgs::Int32::ConstPtr& msg)
{
    right_count = msg->data;
}


class TeleopNode
{
    private:

    public:
    ros::ServiceClient set_m_speed;
    // ros::ServiceClient resetAngle;
    ros::ServiceClient res_encoder_client;
    ros::Subscriber motor0_speed_sub;
    ros::Subscriber teleop_sub;
    // ros::Subscriber motor0_sub;
    ros::Subscriber enc0_dis;
    vmxpi_ros::MotorSpeed speed_msg;
    geometry_msgs::Twist twist_msg;
    // ros::Publisher odom_pub;
    // tf::TransformBroadcaster odom_broadcaster;


    TeleopNode(ros::NodeHandle *nh)
    {
        motor0_speed_sub = nh->subscribe("titan/motor0/speed", 1, motor0_speed_callback);
        teleop_sub = nh->subscribe("cmd_vel", 10, teleoperated_callback);
        // motor0_sub = nh->subscribe("", 1, );
        enc0_dis = nh->subscribe("titan/encoder0/distance", 1, enc0_callback);
        res_encoder_client = nh->serviceClient<std_srvs::Trigger>("titan/reset_encoder");
        set_m_speed = nh->serviceClient<vmxpi_ros::MotorSpeed>("titan/set_motor_speed");
    }

    void motor_control()
    {
        ros::Rate loop_rate(1);
        while(ros::ok())
        {
            speed_msg.request.speed = motor_controller;
            speed_msg.request.motor = 0;
            set_m_speed.call(speed_msg);
            ROS_INFO("Right SPEED = %f ", motor_controller);
            ros::spinOnce();
            loop_rate.sleep();
        }
    }
};



int main(int argc, char **argv)
{
    system("/usr/local/frc/bin/frcKillRobot.sh");
    ros::init(argc, argv, "teleop_node");
    ros::NodeHandle nh;
    VMXPi vmx(true, (uint8_t)50);
    ros::AsyncSpinner spinner(4);
    spinner.start();

    TitanDriverROSWrapper titan(&nh, &vmx);

    TeleopNode my_motor(&nh);
    my_motor.motor_control();


    ROS_INFO("ROS SHUTDOWN");
    ros::waitForShutdown();
}
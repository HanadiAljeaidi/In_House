// Generated by gencpp from file vmxpi_ros/StopMode.msg
// DO NOT EDIT!


#ifndef VMXPI_ROS_MESSAGE_STOPMODE_H
#define VMXPI_ROS_MESSAGE_STOPMODE_H

#include <ros/service_traits.h>


#include <vmxpi_ros/StopModeRequest.h>
#include <vmxpi_ros/StopModeResponse.h>


namespace vmxpi_ros
{

struct StopMode
{

typedef StopModeRequest Request;
typedef StopModeResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StopMode
} // namespace vmxpi_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vmxpi_ros::StopMode > {
  static const char* value()
  {
    return "f4be1905b0e869ab5f98286edb652845";
  }

  static const char* value(const ::vmxpi_ros::StopMode&) { return value(); }
};

template<>
struct DataType< ::vmxpi_ros::StopMode > {
  static const char* value()
  {
    return "vmxpi_ros/StopMode";
  }

  static const char* value(const ::vmxpi_ros::StopMode&) { return value(); }
};


// service_traits::MD5Sum< ::vmxpi_ros::StopModeRequest> should match
// service_traits::MD5Sum< ::vmxpi_ros::StopMode >
template<>
struct MD5Sum< ::vmxpi_ros::StopModeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vmxpi_ros::StopMode >::value();
  }
  static const char* value(const ::vmxpi_ros::StopModeRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vmxpi_ros::StopModeRequest> should match
// service_traits::DataType< ::vmxpi_ros::StopMode >
template<>
struct DataType< ::vmxpi_ros::StopModeRequest>
{
  static const char* value()
  {
    return DataType< ::vmxpi_ros::StopMode >::value();
  }
  static const char* value(const ::vmxpi_ros::StopModeRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vmxpi_ros::StopModeResponse> should match
// service_traits::MD5Sum< ::vmxpi_ros::StopMode >
template<>
struct MD5Sum< ::vmxpi_ros::StopModeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vmxpi_ros::StopMode >::value();
  }
  static const char* value(const ::vmxpi_ros::StopModeResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vmxpi_ros::StopModeResponse> should match
// service_traits::DataType< ::vmxpi_ros::StopMode >
template<>
struct DataType< ::vmxpi_ros::StopModeResponse>
{
  static const char* value()
  {
    return DataType< ::vmxpi_ros::StopMode >::value();
  }
  static const char* value(const ::vmxpi_ros::StopModeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VMXPI_ROS_MESSAGE_STOPMODE_H

// Generated by gencpp from file vmxpi_ros/FloatRes.msg
// DO NOT EDIT!


#ifndef VMXPI_ROS_MESSAGE_FLOATRES_H
#define VMXPI_ROS_MESSAGE_FLOATRES_H

#include <ros/service_traits.h>


#include <vmxpi_ros/FloatResRequest.h>
#include <vmxpi_ros/FloatResResponse.h>


namespace vmxpi_ros
{

struct FloatRes
{

typedef FloatResRequest Request;
typedef FloatResResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct FloatRes
} // namespace vmxpi_ros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vmxpi_ros::FloatRes > {
  static const char* value()
  {
    return "73fcbf46b49191e672908e50842a83d4";
  }

  static const char* value(const ::vmxpi_ros::FloatRes&) { return value(); }
};

template<>
struct DataType< ::vmxpi_ros::FloatRes > {
  static const char* value()
  {
    return "vmxpi_ros/FloatRes";
  }

  static const char* value(const ::vmxpi_ros::FloatRes&) { return value(); }
};


// service_traits::MD5Sum< ::vmxpi_ros::FloatResRequest> should match
// service_traits::MD5Sum< ::vmxpi_ros::FloatRes >
template<>
struct MD5Sum< ::vmxpi_ros::FloatResRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vmxpi_ros::FloatRes >::value();
  }
  static const char* value(const ::vmxpi_ros::FloatResRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vmxpi_ros::FloatResRequest> should match
// service_traits::DataType< ::vmxpi_ros::FloatRes >
template<>
struct DataType< ::vmxpi_ros::FloatResRequest>
{
  static const char* value()
  {
    return DataType< ::vmxpi_ros::FloatRes >::value();
  }
  static const char* value(const ::vmxpi_ros::FloatResRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vmxpi_ros::FloatResResponse> should match
// service_traits::MD5Sum< ::vmxpi_ros::FloatRes >
template<>
struct MD5Sum< ::vmxpi_ros::FloatResResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vmxpi_ros::FloatRes >::value();
  }
  static const char* value(const ::vmxpi_ros::FloatResResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vmxpi_ros::FloatResResponse> should match
// service_traits::DataType< ::vmxpi_ros::FloatRes >
template<>
struct DataType< ::vmxpi_ros::FloatResResponse>
{
  static const char* value()
  {
    return DataType< ::vmxpi_ros::FloatRes >::value();
  }
  static const char* value(const ::vmxpi_ros::FloatResResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VMXPI_ROS_MESSAGE_FLOATRES_H
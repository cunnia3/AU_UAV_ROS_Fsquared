/* Auto-generated by genmsg_cpp for file /home/viki/ros_workspace/AU_UAV_stack/AU_UAV_ROS/srv/StartSimulator.srv */
#ifndef AU_UAV_ROS_SERVICE_STARTSIMULATOR_H
#define AU_UAV_ROS_SERVICE_STARTSIMULATOR_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace AU_UAV_ROS
{
template <class ContainerAllocator>
struct StartSimulatorRequest_ {
  typedef StartSimulatorRequest_<ContainerAllocator> Type;

  StartSimulatorRequest_()
  : indicator()
  {
  }

  StartSimulatorRequest_(const ContainerAllocator& _alloc)
  : indicator(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _indicator_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  indicator;


  typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct StartSimulatorRequest
typedef  ::AU_UAV_ROS::StartSimulatorRequest_<std::allocator<void> > StartSimulatorRequest;

typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorRequest> StartSimulatorRequestPtr;
typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorRequest const> StartSimulatorRequestConstPtr;


template <class ContainerAllocator>
struct StartSimulatorResponse_ {
  typedef StartSimulatorResponse_<ContainerAllocator> Type;

  StartSimulatorResponse_()
  : error()
  {
  }

  StartSimulatorResponse_(const ContainerAllocator& _alloc)
  : error(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _error_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  error;


  typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct StartSimulatorResponse
typedef  ::AU_UAV_ROS::StartSimulatorResponse_<std::allocator<void> > StartSimulatorResponse;

typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorResponse> StartSimulatorResponsePtr;
typedef boost::shared_ptr< ::AU_UAV_ROS::StartSimulatorResponse const> StartSimulatorResponseConstPtr;

struct StartSimulator
{

typedef StartSimulatorRequest Request;
typedef StartSimulatorResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct StartSimulator
} // namespace AU_UAV_ROS

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "31fd107e8c1178343ba30a7979504028";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x31fd107e8c117834ULL;
  static const uint64_t static_value2 = 0x3ba30a7979504028ULL;
};

template<class ContainerAllocator>
struct DataType< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "AU_UAV_ROS/StartSimulatorRequest";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string indicator\n\
\n\
";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "eca8b96616c32aacf1be8bbf14c70eba";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xeca8b96616c32aacULL;
  static const uint64_t static_value2 = 0xf1be8bbf14c70ebaULL;
};

template<class ContainerAllocator>
struct DataType< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "AU_UAV_ROS/StartSimulatorResponse";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string error\n\
\n\
\n\
";
  }

  static const char* value(const  ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.indicator);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct StartSimulatorRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.error);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct StartSimulatorResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<AU_UAV_ROS::StartSimulator> {
  static const char* value() 
  {
    return "deeb10c2d9f6cfc01c3e0da763fa0b2b";
  }

  static const char* value(const AU_UAV_ROS::StartSimulator&) { return value(); } 
};

template<>
struct DataType<AU_UAV_ROS::StartSimulator> {
  static const char* value() 
  {
    return "AU_UAV_ROS/StartSimulator";
  }

  static const char* value(const AU_UAV_ROS::StartSimulator&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "deeb10c2d9f6cfc01c3e0da763fa0b2b";
  }

  static const char* value(const AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "AU_UAV_ROS/StartSimulator";
  }

  static const char* value(const AU_UAV_ROS::StartSimulatorRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "deeb10c2d9f6cfc01c3e0da763fa0b2b";
  }

  static const char* value(const AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "AU_UAV_ROS/StartSimulator";
  }

  static const char* value(const AU_UAV_ROS::StartSimulatorResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // AU_UAV_ROS_SERVICE_STARTSIMULATOR_H

#ifndef _ROS_trims_AAS_h
#define _ROS_trims_AAS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace trims
{

  class AAS : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      typedef float _thrust_type;
      _thrust_type thrust;
      typedef float _ethrust_type;
      _ethrust_type ethrust;
      typedef uint16_t _rpm_type;
      _rpm_type rpm;

    AAS():
      header(),
      voltage(0),
      current(0),
      thrust(0),
      ethrust(0),
      rpm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_thrust;
      u_thrust.real = this->thrust;
      *(outbuffer + offset + 0) = (u_thrust.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_thrust.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_thrust.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_thrust.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thrust);
      union {
        float real;
        uint32_t base;
      } u_ethrust;
      u_ethrust.real = this->ethrust;
      *(outbuffer + offset + 0) = (u_ethrust.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ethrust.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ethrust.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ethrust.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ethrust);
      *(outbuffer + offset + 0) = (this->rpm >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rpm >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rpm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_thrust;
      u_thrust.base = 0;
      u_thrust.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_thrust.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_thrust.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_thrust.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->thrust = u_thrust.real;
      offset += sizeof(this->thrust);
      union {
        float real;
        uint32_t base;
      } u_ethrust;
      u_ethrust.base = 0;
      u_ethrust.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ethrust.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ethrust.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ethrust.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ethrust = u_ethrust.real;
      offset += sizeof(this->ethrust);
      this->rpm =  ((uint16_t) (*(inbuffer + offset)));
      this->rpm |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rpm);
     return offset;
    }

    const char * getType(){ return "trims/AAS"; };
    const char * getMD5(){ return "8de1f82d04e277e5dad779829ff95576"; };

  };

}
#endif

#ifndef SR_MOBI_PID_CORE_H
#define SR_MOBI_PID_CORE_H

#include "ros/ros.h"
#include "ros/time.h"

// Custom message includes. Auto-generated from msg/ directory.
#include <mobi_msgs/PID.h>

// Dynamic reconfigure includes.
#include <dynamic_reconfigure/server.h>
// Auto-generated from cfg/ directory.
#include <mobi_pid/mobiPIDConfig.h>

class MobiPID
{
public:
  MobiPID();
  ~MobiPID();
  void configCallback(mobi_pid::mobiPIDConfig &config, double level);
  void publishMessage(ros::Publisher *pub_message);
  void messageCallback(const mobi_msgs::PID::ConstPtr &msg);

  double p_;
  double d_;
  double i_;

};
#endif

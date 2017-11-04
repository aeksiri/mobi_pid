#include "mobi_pid/mobi_pid_core.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pid_configure");
  ros::NodeHandle nh;

  mobiPID *mobi_pid = new mobiPID();

  dynamic_reconfigure::Server<mobi_pid::mobiPIDConfig> dr_srv;
  dynamic_reconfigure::Server<mobi_pid::mobiPIDConfig>::CallbackType cb;
  cb = boost::bind(&mobiPID::configCallback, mobi_pid, _1, _2);
  dr_srv.setCallback(cb);

  double p;
  double d;
  double i;
  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("p", p, 0.05);
  pnh.param("d", d, 0.10);
  pnh.param("i", i, 0.00);
  pnh.param("rate", rate, 1);

  ros::Publisher pub_message = nh.advertise<mobi_msgs::PID>("pid", 10);

  ros::Rate r(rate);

  while (nh.ok())
  {
    mobi_pid->publishMessage(&pub_message);
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}

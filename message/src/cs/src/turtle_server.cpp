//生成一个服务，当收到turtle_command消息时，将pub_command取反，以此控制cmd_vel消息的发送，达到控制海龟运动的效果
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pub_command = false;

bool commandCallBack(std_srvs::Trigger::Request &req,
                     std_srvs::Trigger::Response &res) {
    pub_command = !pub_command;

    ROS_INFO("publish turtle velocity command %s",
             pub_command == true?"Yes":"No");

    res.success = true;
    res.message = "Change turtlecommand state";

    return true;

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "turtle_server");
  ros::NodeHandle node;

  ros::ServiceServer service =
      node.advertiseService("/turtle_command", commandCallBack);

  turtle_vel_pub = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  ROS_INFO("waitting for turtle command");

  ros::Rate loop_rate(10);

  while (ros::ok()) {
    ros::spinOnce();

    if (pub_command) {
      geometry_msgs::Twist vel_msg;
      vel_msg.linear.x = 0.5;
      vel_msg.angular.z = 0.2;
      turtle_vel_pub.publish(vel_msg);
    }

    loop_rate.sleep();
  }

  return 0;
}
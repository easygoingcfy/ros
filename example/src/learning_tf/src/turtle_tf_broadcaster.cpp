//产生tf数据， 计算、发布turtle2的速度指令

#include "tf/transform_broadcaster.h"
#include "turtlesim/Pose.h"
#include <ros/ros.h>

std::string turtle_name;

void poseCallBack(const turtlesim::PoseConstPtr &msg) {
  static tf::TransformBroadcaster br;

  tf::Transform transform;
  transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));
  tf::Quaternion q;
  q.setRPY(0, 0, msg->theta);
  transform.setRotation(q);

  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));

}

int main(int argc, char** argv) {
    ros::init(argc, argv, "my_tf_broadcaster");

    if (argc != 2) {
        ROS_ERROR("need turtle name as argument");
        return -1;
    }
    turtle_name = argv[1];

    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name + "/pose", 10, &poseCallBack);

    ros::spin();

    return 0;
}
#include <ros/ros.h>
#include "turtlesim/Pose.h"


void PoseCallBack(const turtlesim::Pose::ConstPtr& msg) {
    ROS_INFO("Turtle pose: x: %0.6f, y: %0.6f", msg->x, msg->y);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "pose_subscriber");
    ros::NodeHandle n;

    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, PoseCallBack);

    ros::spin();

    return 0;
}
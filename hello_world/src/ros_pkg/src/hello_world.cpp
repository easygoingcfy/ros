#include <ros/ros.h>

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "hello");
    ros::NodeHandle n;
    ROS_INFO("fuck you the hello world");

    return 0;
}
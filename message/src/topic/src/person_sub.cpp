#include <ros/ros.h>
#include "topic/person.h"

void PersonCallBack(const topic::person::ConstPtr& msg) {
    ROS_INFO("Subscribe Person: name: %s age: %d sex: %d",
             msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "person_sub");
    ros::NodeHandle n;

    ros::Subscriber person_sub = n.subscribe("/person_info", 10, PersonCallBack);

    ros::spin();

    return 0;
}
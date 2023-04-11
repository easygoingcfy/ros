#include <ros/ros.h>
#include "topic/person.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "person_pubhahaha");
    ros::NodeHandle n;

    ros::Publisher person_pub = n.advertise<topic::person>("/person_info", 10);
    ros::Rate loop_rate(1);

    while (ros::ok()) {
        topic::person cfy;
        cfy.name = "caofangyu";
        cfy.age = 26;
        cfy.sex = topic::person::male;

        person_pub.publish(cfy);
        ROS_INFO("Publish cfy: age: %d, sex: %d", cfy.age, cfy.sex);
        loop_rate.sleep();
    }

    return 0;
}
#include <ros/ros.h>
#include "turtlesim/Spawn.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "tutle_spawn");
    ros::NodeHandle node;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle_cfy";

    ROS_INFO("call service to spawn turtle[x: %0.6f y: %0.6f name: %s]",
            srv.request.x ,srv.request.y, srv.request.name);
    add_turtle.call(srv);
    ROS_INFO("Spawn turtle successful [name: %s]", srv.response.name.c_str());

    return 0;
}
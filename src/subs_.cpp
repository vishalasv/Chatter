#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include "string.h"

void message_pub(const std_msgs::String::ConstPtr &mes)
{
    ROS_INFO("Message : %s ",mes->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subs");
    ros::NodeHandle nh;

    

    ros::Subscriber s = nh.subscribe("chat1",1000,&message_pub);
    
    ros::spin();


    return 0;
}
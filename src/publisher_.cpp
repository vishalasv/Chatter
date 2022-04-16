#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include "string.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "publ");
    ros::NodeHandle nh;

    char input[1000];

    ros::Publisher p = nh.advertise<std_msgs::String>("chat1",1000);
    ros::Rate rate(10);

    while(ros::ok)
    {
        std_msgs::String msg;

        printf("\nEnter the message to send :  ");
        
        fgets(input,998,stdin);

        msg.data=input;

        p.publish(msg);

        rate.sleep();

    }


    return 0;
}
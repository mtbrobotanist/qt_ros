
#include "MainWindow.h"
#include <ros/ros.h>
#include <std_msgs/Int32.h>

MainWindow::MainWindow():
timer(new QTimer(this))
{
    widget.setupUi(this);

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("pub_5", 5);

    connect(timer, &QTimer::timeout, this,
            [=](){
                std_msgs::Int32 msg;
                msg.data = 5;
                pub.publish(msg);
            });
            
    timer->start(0);
}

MainWindow::~MainWindow()
{
}

/*
 * File:   MainWindow.cpp
 * Author: serl
 *
 * Created on September 15, 2016, 12:01 PM
 */

#include "MainWindow.h"
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <QTimer>

MainWindow::MainWindow()
{
    widget.setupUi(this);
    timer = new QTimer(this);
    
    ros::NodeHandle nh;
    
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic_name", 5);
    
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

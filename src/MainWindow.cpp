
#include "MainWindow.h"
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

MainWindow::MainWindow():
    linear_scale(2),
    angular_scale(2),
    linear(0),
    angular(0)
{
    widget.setupUi(this);

    pub_cmd_vel = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    
    image_transport::ImageTransport it{nh};
    
    sub_img = it.subscribe("/usb_cam/image_raw", 100, &MainWindow::ImageCallback, this);


    connect(widget.btn_up, &QPushButton::clicked,
            this, &MainWindow::OnUpClicked);
    connect(widget.btn_left, &QPushButton::clicked,
            this, &MainWindow::OnLeftClicked);
    connect(widget.btn_right, &QPushButton::clicked,
            this, &MainWindow::OnRightClicked);
    connect(widget.btn_down, &QPushButton::clicked,
            this, &MainWindow::OnDownClicked);   
}

MainWindow::~MainWindow()
{
}

void MainWindow::ImageCallback(const sensor_msgs::ImageConstPtr& in)
{
    ROS_WARN_STREAM("in image callback");
    
    QImage::Format f = QImage::Format_RGB888;
    QImage img(in->data.data(), in->width, in->height, in->step, f);
//    img = img.rgbSwapped();
    
    QPixmap pic = QPixmap::fromImage(img);
    
    int w = widget.image_frame->width();
    int h = widget.image_frame->height();
    
    pic = pic.scaled(w, h, Qt::KeepAspectRatio);
    widget.image_frame->setPixmap(pic);
}

void MainWindow::TranslateAndPublish()
{
    geometry_msgs::Twist twist;
    twist.angular.z = angular_scale * angular;
    twist.linear.x = linear_scale * linear;
    pub_cmd_vel.publish(twist);
    
    linear = angular = 0;
}

void MainWindow::OnLeftClicked()
{
    angular = 1;
    this->TranslateAndPublish();
}

void MainWindow::OnRightClicked()
{
    angular = -1;
    this->TranslateAndPublish();
}

void MainWindow::OnUpClicked()
{
    linear = 1;
    this->TranslateAndPublish();
}

void MainWindow::OnDownClicked()
{
    linear = -1;
    this->TranslateAndPublish();
}
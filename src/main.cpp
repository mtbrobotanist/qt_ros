
#include <QApplication>
#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    ros::init(argc, argv, "qt_ros_node");

    MainWindow m;
    m.show();
    // create and show your widgets here

    return app.exec();
}

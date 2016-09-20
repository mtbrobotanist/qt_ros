# qt_ros
A standalone bare-bones repository for creating ros applications with qt that doesn't rely on rqt, using cmake.

ros: http://www.ros.org/

qt:  https://www.qt.io/

The general structure is:

    src/            (*.cpp goes here)
      |- main.cpp   (the main entry point into a QApplication, contains ros::init())
    include/        (*.h goes here)
    resources/      (*.ui goes here)
      |- qrc/       (*.qrc goes here)
    CMakeLists.txt


This repository is designed to be cloned into the src directory of a catkin
workspace. That is, a workspace created by running the command `catkin_init_workspace`
from inside src (but not the src dir of this repository!).
see here: http://wiki.ros.org/catkin/Tutorials/create_a_workspace

The CmakeLists.txt file is already configured to automatically compile all files
into a shared library (lib_qt_ros.so) which is linked to the executable created
from main.cpp, so long as you put the appropriate files in their respective directory.
Don't move main.cpp unless you want to edit CMakelists.txt yourself.

For those new to qt don't trip if when examining your headers you see `#include "ui_<my_file>.h"`
and it doesn't exist yet. Just run `catkin_make` from the root of your catkin workspace and
the qt build system will create them for you in the auto generated `build` directory.

Oh and it contains MainWindow.[ui | h | cpp] example complete with ros node initialization and
publishing.

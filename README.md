# qt_ros
A standalone bare-bones repository for creating ros applications with qt that
don't rely on rqt, using cmake.

ros: http://www.ros.org/      qt:  https://www.qt.io/

the general structure is:

    src/            (*.cpp goes here)
      |- main.cpp   (the main entry point into a QApplication)
    include/        (*.h goes here)
    resources/      (*.ui goes here)
      |- qrc/       (*.qrc goes here)
    CMakeLists.txt


This repository is designed to be cloned into the src directory of a catkin
workspace. That is, a workspace created by running the command `catkin_init_workspace`
from inside src. see here: http://wiki.ros.org/catkin/Tutorials/create_a_workspace

The CmakeLists.txt file is already configured to automatically compile all files
into a shared library (lib_qt_ros.so) which is linked to the executable created
from main.cpp, so long as you put the appropriate files in their respective directory.
Don't move main.cpp unless you want to edit CMakelists.txt yourself.

For those new to qt, the ui_*.h files that get created by the qt build system
will be in qt_ros/build after running `catkin_make`. Don't trip if when
examining your headers you see `#include "ui_<my_file>.h"` and it doesn't exist
yet. just run `catkin_make` form the root of your catkin workspace.
See the url above for more info.

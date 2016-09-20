
/* 
 * File:   MainWindow.h
 * Author: serl
 *
 * Created on September 15, 2016, 12:01 PM
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "ui_MainWindow.h"
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
    QTimer* timer;
};

#endif /* _MAINWINDOW_H */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "login.h"

/**********************************************************************************************************************************
 *
 * Project Title:ChatRoom
 *
 * Author:PanYao Nju
 *
 * Brief:一次关于C/C++技术栈的应用实践
 *
 * ********************************************************************************************************************************/

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LogIn* _login;
};
#endif // MAINWINDOW_H

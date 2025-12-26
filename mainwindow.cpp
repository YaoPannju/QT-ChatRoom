#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主窗口一开始初始化为登陆界面
    _login = new LogIn();
    setCentralWidget(_login);
    _login->show();

    QSize loginSize = _login->size();

    qDebug() << "获取到的登录界面大小:" << loginSize;

    this->resize(loginSize);

    //初始化注册界面
    _register = new Register();

    connect(_login, &LogIn::switchRegister, this, &MainWindow::SwitchLgnToReg);

}

MainWindow::~MainWindow()
{
    delete ui;
    if(_login){
        delete _login;
        _login = nullptr;
    }
    if(_register){
        delete _register;
        _register = nullptr;
    }
}

void MainWindow::SwitchLgnToReg(){
    setCentralWidget(_register);
    _login->hide();
    _register->show();
}

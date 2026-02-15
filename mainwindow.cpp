#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _login = nullptr;
    _register = nullptr;

    showLoginDialog();

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

void MainWindow::showLoginDialog() {
    if(!_login){
        _login = new LogIn();
        connect(_login, &LogIn::switchRegister, this, &MainWindow::SwitchL2R);
    }
    _login->exec();
}

void MainWindow::showRegisterDialog(){
    if(!_register){
        _register = new Register();
        connect(_register, &Register::BackLogin, this, &MainWindow::SwitchR2L);
    }
    _register->exec();
}

void MainWindow::SwitchL2R(){
    if(_login){
        _login->accept();
        delete _login;
        _login = nullptr;
    }
    showRegisterDialog();
}

void MainWindow::SwitchR2L(){
    if(_register){
        _register->accept();
        delete _register;
        _register = nullptr;
    }
    showLoginDialog();
}

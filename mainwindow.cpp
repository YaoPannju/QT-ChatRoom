#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _login = new LogIn();
    setCentralWidget(_login);
    _login->show();

    QSize loginSize = _login->size();

    qDebug() << "获取到的登录界面大小:" << loginSize;

    this->resize(loginSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

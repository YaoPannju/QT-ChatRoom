#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
    connect(ui->RegButton, &QPushButton::clicked, this, &LogIn::switchRegister);
}

LogIn::~LogIn()
{
    delete ui;
}

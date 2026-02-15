#include "register.h"
#include "ui_register.h"
#include "Global.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    //密码输入保护模式
    ui->New_pwd->setEchoMode(QLineEdit::Password);
    ui->Confirm_New_pwd->setEchoMode(QLineEdit::Password);
    connect(ui->Cancel_Button, &QPushButton::clicked, this, &Register::BackLogin);

    //err_tip状态属性
    ui->err_tip->setProperty("state", "normal");
    repolish(ui->err_tip);
}

Register::~Register()
{
    delete ui;
}


void Register::on_GetConfirm_Button_clicked()
{
    auto email = ui->Email_Edit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码
    }
    else{
        showTip(tr("邮箱地址不正确"), false);
    }
}

void Register::showTip(QString str, bool b_ok)
{
    if(!b_ok){
        ui->err_tip->setProperty("state", "error");
    }
    else{
        ui->err_tip->setProperty("state", "normal");
    }
    ui->err_tip->setText(str);
    ui->err_tip->adjustSize();
    repolish(ui->err_tip);
}


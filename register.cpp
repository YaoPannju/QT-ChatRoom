#include "register.h"
#include "ui_register.h"

#include "httpmgr.h"

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

    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish, this, &Register::slot_reg_mod_finish);

    initHttpHandlers();
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

void Register::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        showTip(tr("json解析错误"),false);
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误"),false);
        return;
    }

    //调用对应的逻辑,根据id回调。
    _handlers[id](jsonDoc.object());

    return;
}

void Register::initHttpHandlers()
{
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送到邮箱，注意查收"), true);
        qDebug()<< "email is " << email ;
    });
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


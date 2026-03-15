#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QLineEdit>
#include <QRegularExpression>

#include "Global.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

signals:
    void BackLogin();

private slots:
    void on_GetConfirm_Button_clicked();

public slots:
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);

private:
    Ui::Register *ui;
    void initHttpHandlers();
    void showTip(QString str, bool b_ok);
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;
};

#endif // REGISTER_H

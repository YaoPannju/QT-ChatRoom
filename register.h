#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QLineEdit>
#include <QRegularExpression>

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

private:
    Ui::Register *ui;

    void showTip(QString str, bool b_ok);
};

#endif // REGISTER_H

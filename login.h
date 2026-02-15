#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

signals:
    void switchRegister();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H

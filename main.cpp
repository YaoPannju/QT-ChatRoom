#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon icon(":/img/Robin.ico");
    if (!icon.isNull()) {
        a.setWindowIcon(icon);
        qDebug() << "图标加载成功";
    } else {
        qDebug() << "图标加载失败，检查 Robin.ico 文件路径";
    }

    MainWindow w;
    w.show();
    return a.exec();
}

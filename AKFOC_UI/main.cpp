#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/background/icon.ico"));// 设置程序图标
    a.setStyleSheet("QWidget { font-weight: bold; }");// 字体更改为粗体
    MainWindow w;
    w.show();
    return a.exec();
}

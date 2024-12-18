// authenticator.cpp
#include "authenticator.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

bool Authenticator::authenticateUser(const char *username, const char *password)
{
    QFile file("account.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open account.txt";
        return false;
    }

    QTextStream in(&file);
    //逐行读取account.txt
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

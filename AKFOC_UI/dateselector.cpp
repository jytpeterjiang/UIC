// dateselector.cpp
#include "dateselector.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDate>
#include <QDateTime>

time_t DateSelector::selectDate()
{
    QDialog dialog;
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *titleLabel = new QLabel("Select Date", &dialog);

    // 获取当前日期及其后续日期
    QDate currentDate = QDate::currentDate();
    QDate tomorrowDate = currentDate.addDays(1);
    QDate dayAfterTomorrowDate = currentDate.addDays(2);

    // 创建按钮并设置文本
    QPushButton *todayButton = new QPushButton(QString("Today (%1)").arg(currentDate.toString("dd/MM/yyyy")), &dialog);
    QPushButton *tomorrowButton = new QPushButton(QString("Tomorrow (%1)").arg(tomorrowDate.toString("dd/MM/yyyy")), &dialog);
    QPushButton *dayAfterTomorrowButton = new QPushButton(QString("The Day After Tomorrow (%1)").arg(dayAfterTomorrowDate.toString("dd/MM/yyyy")), &dialog);
    QPushButton *backButton = new QPushButton("Back", &dialog);

    layout->addWidget(titleLabel);
    layout->addWidget(todayButton);
    layout->addWidget(tomorrowButton);
    layout->addWidget(dayAfterTomorrowButton);
    layout->addWidget(backButton);

    time_t selectedDate = 0;

    QObject::connect(todayButton, &QPushButton::clicked, [&]() {
        selectedDate = QDateTime::currentDateTime().toSecsSinceEpoch();
        dialog.accept();
    });

    QObject::connect(tomorrowButton, &QPushButton::clicked, [&]() {
        selectedDate = QDateTime::currentDateTime().addDays(1).toSecsSinceEpoch();
        dialog.accept();
    });

    QObject::connect(dayAfterTomorrowButton, &QPushButton::clicked, [&]() {
        selectedDate = QDateTime::currentDateTime().addDays(2).toSecsSinceEpoch();
        dialog.accept();
    });

    QObject::connect(backButton, &QPushButton::clicked, [&]() {
        dialog.reject();
    });

    dialog.exec();
    return selectedDate;
}

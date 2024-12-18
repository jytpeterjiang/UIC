// bookingrecorder.cpp
#include "bookingrecorder.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void BookingRecorder::recordBooking(const char *classroom, int timeslot, const char *username, time_t selectedDate)
{
    // 打开教室预订文件
    QFile file(QString("%1_bookings.txt").arg(classroom));
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open booking file for classroom:" << classroom;
        return;
    }

    // 创建文本流对象
    QTextStream out(&file);
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(selectedDate));
    QDate date = dateTime.date();
    int startHour = timeslot;

    // 写入预订记录
    out << QString("Date: %1/%2/%3, Timeslot: %4:%5-%4:%6, User: %7\n")
               .arg(date.day())
               .arg(date.month())
               .arg(date.year())
               .arg(startHour, 2, 10, QChar('0'))  // 确保小时部分至少有两位数，防止查找出错
               .arg("00")
               .arg("50")
               .arg(username);

    file.close();
    qDebug() << "Booking recorded for classroom:" << classroom << "at" << dateTime.toString("dd/MM/yyyy hh:mm") << "User:" << username;
}


bool BookingRecorder::isClassroomBooked(const char *classroom, int timeslot, time_t selectedDate)
{
    // 打开教室预订文件
    QFile file(QString("%1_bookings.txt").arg(classroom));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open booking file for classroom:" << classroom;
        return false;
    }

    // 创建文本流对象
    QTextStream in(&file);
    QDateTime selectedDateTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(selectedDate));
    QDate selectedQDate = selectedDateTime.date();
    QString selectedDateString = selectedQDate.toString("dd/MM/yyyy");
    qDebug() << "Checking bookings for classroom:" << classroom << "on:" << selectedDateString << "timeslot:" << timeslot;

    // 逐行读取预订文件
    while (!in.atEnd()) {
        QString line = in.readLine();
        QRegularExpression re("Date: (\\d{2}/\\d{2}/\\d{4}), Timeslot: (\\d{2}):00-\\d{2}:50, User: (.+)");
        QRegularExpressionMatch match = re.match(line);

        // 检查是否匹配格式
        if (match.hasMatch()) {
            QString datePart = match.captured(1);
            QDate bookedDate = QDate::fromString(datePart, "dd/MM/yyyy");

            int bookedTimeslot = match.captured(2).toInt();

            QString bookedDateString = bookedDate.toString("dd/MM/yyyy");
            qDebug() << "Checking booking:" << bookedDateString << "timeslot:" << bookedTimeslot;

            // 确保日期和时间槽格式一致
            if (bookedTimeslot == timeslot && bookedDate >= selectedQDate) {
                file.close();
                return true;
            }
        }
    }

    // 如果没有找到匹配的预订记录，关闭文件并返回 false
    file.close();
    return false;
}

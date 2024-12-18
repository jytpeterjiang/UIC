#include "classroomsearcher.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "bookingrecorder.h"
#include <QDateTime>
#include <QDate>
#include <QMessageBox>

char* ClassroomSearcher::findAvailableClassroom(int requiredSize, int timeslot, time_t selectedDate)
{
    QFile file("classroom_info.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open classroom_info.txt";
        return nullptr;
    }

    QTextStream in(&file);
    BookingRecorder bookingRecorder;
    //日期格式的转换
    QDateTime selectedDateTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(selectedDate));
    QDate selectedQDate = selectedDateTime.date();
    QString selectedDateString = selectedQDate.toString("dd/MM/yyyy");
    qDebug() << "Searching for available classroom on:" << selectedDateString << "timeslot:" << timeslot;
    //逐行读取classroom.txt文件
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() == 2) {
            int size = parts[1].toInt();
            if (size >= requiredSize) {
                if (!bookingRecorder.isClassroomBooked(parts[0].toStdString().c_str(), timeslot, selectedDate)) {
                    file.close();
                    return strdup(parts[0].toStdString().c_str());
                }
            }
        }
    }

    file.close();
    return nullptr;
}

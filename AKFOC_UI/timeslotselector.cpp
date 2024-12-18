// timeslotselector.cpp
#include "timeslotselector.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QMessageBox>

int TimeSlotSelector::selectTimeSlot(time_t selectedDate)
{
    QDialog dialog;
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *titleLabel = new QLabel("Select Time Slot", &dialog);
    QPushButton *backButton = new QPushButton("Back", &dialog);
    //QPushButton *exitButton = new QPushButton("Exit", &dialog);

    layout->addWidget(titleLabel);

    QDateTime selectedDateTime = QDateTime::fromSecsSinceEpoch(selectedDate);
    QDateTime currentDateTime = QDateTime::currentDateTime();

    int startHour = 9;
    int endHour = 17;

    if (selectedDateTime.date() == currentDateTime.date()) {
        if (currentDateTime.time().hour() >= 17) {
            //QMessageBox::information(&dialog, "Info", "No available timeslots for today. Please choose another date.");
            return -3;
        }
        startHour = currentDateTime.time().hour() + 1;
    }

    int numTimeSlots = endHour - startHour;

    if (numTimeSlots >= 8) {
        startHour = 9;
        numTimeSlots = 8;
    }

    int selectedTimeSlot = -1;

    for (int i = 0; i < numTimeSlots; ++i) {
        int timeSlotStart = startHour + i;
        QPushButton *timeSlotButton = new QPushButton(QString("%1:00 - %1:50").arg(timeSlotStart), &dialog);
        QObject::connect(timeSlotButton, &QPushButton::clicked, [&dialog, &selectedTimeSlot, timeSlotStart]() {
            selectedTimeSlot = timeSlotStart;
            dialog.accept();
        });
        layout->addWidget(timeSlotButton);
    }

    layout->addWidget(backButton);
    //layout->addWidget(exitButton);

    QObject::connect(backButton, &QPushButton::clicked, [&dialog]() {
        dialog.reject();
    });
    /*
    QObject::connect(exitButton, &QPushButton::clicked, [&dialog]() {
        dialog.reject();
    });
    */
    int result = dialog.exec();
    if (result == QDialog::Accepted) {
        return selectedTimeSlot;
    } else {
        return -1;
    }
}

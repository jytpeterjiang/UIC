// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "authenticator.h"
#include "dateselector.h"
#include "timeslotselector.h"
#include "classroomsearcher.h"
#include "bookingrecorder.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onSelectDateClicked();
    void onSelectTimeSlotClicked();
    void onFindClassroomClicked();
    void onConfirmBookingClicked();
    void onContinueBookingClicked();
    void onExitClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLabel *statusLabel;
    QPushButton *dateSelectButton;
    QLabel *dateDisplayLabel;
    QPushButton *timeSlotSelectButton;
    QLabel *timeSlotDisplayLabel;
    QLineEdit *classroomSizeEdit;
    QPushButton *findClassroomButton;
    QLabel *classroomDisplayLabel;
    QPushButton *confirmBookingButton;
    QPushButton *continueBookingButton;
    QPushButton *exitButton;

    Authenticator authenticator;
    DateSelector dateSelector;
    TimeSlotSelector timeSlotSelector;
    ClassroomSearcher classroomSearcher;
    BookingRecorder bookingRecorder;

    time_t selectedDate;
    int selectedTimeSlot;
    int requiredSize;
    QString selectedClassroom;

    bool isLoggedIn;  // 新增：记录用户是否已登录
    int loginAttempts;  // 新增：记录登录尝试次数

    bool checkIfLoggedIn();  // 新增：检查用户是否已登录
};

#endif // MAINWINDOW_H

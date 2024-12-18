// mainwindow.cpp
#include "mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), isLoggedIn(false), loginAttempts(0), selectedDate(0), selectedTimeSlot(-1)  // 初始化变量
{
    // 调整窗口大小以适应背景图片
    setFixedSize(500, 500);

    // 初始化UI组件
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);
    statusLabel = new QLabel("Welcome to the classroom booking system!", this);
    dateSelectButton = new QPushButton("Select Date", this);
    dateDisplayLabel = new QLabel("Selected Date: None", this);
    timeSlotSelectButton = new QPushButton("Select Time Slot", this);
    timeSlotDisplayLabel = new QLabel("Selected Time Slot: None", this);
    classroomSizeEdit = new QLineEdit(this);
    findClassroomButton = new QPushButton("Find Classroom", this);
    classroomDisplayLabel = new QLabel("Available Classroom: None", this);
    confirmBookingButton = new QPushButton("Confirm Booking", this);
    continueBookingButton = new QPushButton("Clear up", this);
    exitButton = new QPushButton("Exit", this);

    // 设置按钮样式
    /*
    QString buttonStyle = "QPushButton { background: transparent; border: 1px solid black; color: black; }";
    loginButton->setStyleSheet(buttonStyle);
    dateSelectButton->setStyleSheet(buttonStyle);
    timeSlotSelectButton->setStyleSheet(buttonStyle);
    findClassroomButton->setStyleSheet(buttonStyle);
    confirmBookingButton->setStyleSheet(buttonStyle);
    continueBookingButton->setStyleSheet(buttonStyle);
    exitButton->setStyleSheet(buttonStyle);
    */
    // 创建一个QWidget作为背景容器
    QWidget *backgroundWidget = new QWidget(this);
    //backgroundWidget->setStyleSheet("background-image: url(:/background/background_2.png); background-repeat: no-repeat; background-position: above;background-position: center; opacity: 0.5;");
    //backgroundWidget->setGeometry(0, 0, 500, 500); // 设置背景容器的大小和位置

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(statusLabel);
    layout->addWidget(new QLabel("Username:", this));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("Password:", this));
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(dateSelectButton);
    layout->addWidget(dateDisplayLabel);
    layout->addWidget(timeSlotSelectButton);
    layout->addWidget(timeSlotDisplayLabel);
    layout->addWidget(new QLabel("Classroom Size:", this));
    layout->addWidget(classroomSizeEdit);
    layout->addWidget(findClassroomButton);
    layout->addWidget(classroomDisplayLabel);
    layout->addWidget(confirmBookingButton);
    layout->addWidget(continueBookingButton);
    layout->addWidget(exitButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // 将centralWidget添加到backgroundWidget上
    backgroundWidget->setGeometry(0, 0, 500, 500); // 设置背景容器的大小和位置
    backgroundWidget->setAutoFillBackground(true);
    backgroundWidget->setStyleSheet("QWidget { background-color: transparent; }");
    backgroundWidget->setStyleSheet("background-image: url(:/background/background_2.png); background-repeat: no-repeat; background-position: center;");
    //backgroundWidget->setStyleSheet("background-image: url(:/background/words.png); background-repeat: no-repeat; background-position: under;background-color: rgba(255, 255, 255, 1);");

    // 连接信号与槽
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(dateSelectButton, &QPushButton::clicked, this, &MainWindow::onSelectDateClicked);
    connect(timeSlotSelectButton, &QPushButton::clicked, this, &MainWindow::onSelectTimeSlotClicked);
    connect(findClassroomButton, &QPushButton::clicked, this, &MainWindow::onFindClassroomClicked);
    connect(confirmBookingButton, &QPushButton::clicked, this, &MainWindow::onConfirmBookingClicked);
    connect(continueBookingButton, &QPushButton::clicked, this, &MainWindow::onContinueBookingClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onLoginClicked()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both username and password.");
        return;  // 输入为空不增加登录尝试次数，直接返回
    }

    if (authenticator.authenticateUser(username.toStdString().c_str(), password.toStdString().c_str())) {
        statusLabel->setText(QString("Welcome %1!").arg(username));
        isLoggedIn = true;
        loginAttempts = 0;  // 重置登录尝试次数
    } else {
        loginAttempts++;
        if (loginAttempts >= 3) {
            QMessageBox::critical(this, "Error", "Too many failed login attempts. Exiting...");
            close();  // 直接退出程序
        } else {
            statusLabel->setText("Invalid account name or password!");
        }
    }
}

void MainWindow::onSelectDateClicked()
{
    if (!checkIfLoggedIn()) return;  // 如果未登录则返回
    selectedDate = dateSelector.selectDate();
    if (selectedDate != 0) {
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(selectedDate));
        QDate date = dateTime.date();
        dateDisplayLabel->setText(QString("Selected Date: %1/%2/%3")
                                      .arg(date.day())
                                      .arg(date.month())
                                      .arg(date.year()));
    }
}

void MainWindow::onSelectTimeSlotClicked()
{
    if (!checkIfLoggedIn()) return;  // 如果未登录则返回
    if (selectedDate == 0) {
        QMessageBox::warning(this, "Warning", "Please select a date first.");
        return;  // 如果没有选择日期，则不能选择时间段
    }
    selectedTimeSlot = timeSlotSelector.selectTimeSlot(selectedDate);
    if (selectedTimeSlot == -3) {  // 没有可用时间段
        timeSlotDisplayLabel->setText("Selected Time Slot: None");
        QMessageBox::information(this, "Info", "No available timeslots for the selected date. Please choose another date.");
    } else if (selectedTimeSlot != -1) {
        timeSlotDisplayLabel->setText(QString("Selected Time Slot: %1:00 - %2:50")
                                          .arg(selectedTimeSlot)
                                          .arg(selectedTimeSlot));
    } else {
        timeSlotDisplayLabel->setText("Selected Time Slot: None");
    }
}

void MainWindow::onFindClassroomClicked()
{
    if (!checkIfLoggedIn()) return;  // 如果未登录则返回
    if (selectedTimeSlot == -1 || selectedTimeSlot == -3) {
        QMessageBox::warning(this, "Warning", "Please select a time slot first.");
        return;  // 如果没有选择时间段，则不能查找教室
    }
    int requiredSize = 0;
    requiredSize = classroomSizeEdit->text().toInt();
    if (requiredSize <= 0) {
        QMessageBox::warning(this, "Warning","Please input your classroom size(>0)!");
        return;
    }
    selectedClassroom = QString::fromUtf8(classroomSearcher.findAvailableClassroom(requiredSize, selectedTimeSlot, selectedDate));
    if (!selectedClassroom.isEmpty()) {
        classroomDisplayLabel->setText(QString("Available Classroom: %1").arg(selectedClassroom));
    } else {
        classroomDisplayLabel->setText("No available room!");
    }
}

void MainWindow::onConfirmBookingClicked()
{
    if (!checkIfLoggedIn()) return;  // 如果未登录则返回
    if (selectedClassroom.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a classroom first.");
        return;  // 如果没有选择教室，则不能确认预订
    }
    bookingRecorder.recordBooking(selectedClassroom.toStdString().c_str(), selectedTimeSlot, usernameEdit->text().toStdString().c_str(), selectedDate);
    statusLabel->setText("Booking recorded successfully!");
}

void MainWindow::onContinueBookingClicked()
{
    if (!checkIfLoggedIn()) return;  // 如果未登录则返回
    // Reset UI components for next booking
    dateDisplayLabel->setText("Selected Date: None");
    timeSlotDisplayLabel->setText("Selected Time Slot: None");
    classroomDisplayLabel->setText("Available Classroom: None");
    classroomSizeEdit->clear();
    selectedDate = 0;
    selectedTimeSlot = -1;
}

void MainWindow::onExitClicked()
{
    close();
}

bool MainWindow::checkIfLoggedIn()
{
    if (!isLoggedIn) {
        QMessageBox::warning(this, "Warning", "You must log in first!");
        return false;
    }
    return true;
}

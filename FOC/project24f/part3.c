
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定义教室结构体
typedef struct Classroom {
    int id;
    int size;
    int isAvailable[9];  // 用于记录每个时间段的可用性，9个时间段对应9个元素
    char reservedBy[9][50];  // 记录预订每个时间段的用户名
} Classroom;

// 定义账户结构体
typedef struct Account {
    char username[50];
    char password[50];
} Account;

// 全局变量，存储教室和账户信息
Classroom classrooms[100];  // 假设最多100个教室
Account accounts[100];  // 假设最多100个账户
int numClassrooms = 0;
int numAccounts = 0;

// 函数声明
void loadAccounts();
void loadClassrooms();
void saveClassroomStatus(Classroom *classroom);
void displayAvailableSlots(int option);
int findAvailableClassroom(int size);

int main() {
    loadAccounts();
    loadClassrooms();

    // 假设已经完成登录，直接进入选择时间段流程，这里假设选择今天（可根据实际情况修改）
    displayAvailableSlots(1);

    return 0;
}

// 从文件加载账户信息
void loadAccounts() {
    FILE *fp;
    fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("无法打开账户文件。\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", accounts[numAccounts].username, accounts[numAccounts].password) == 2) {
        numAccounts++;
    }

    fclose(fp);
}

// 从文件加载教室信息并初始化可用性
void loadClassrooms() {
    FILE *fp;
    fp = fopen("classroom_info.txt", "r");
    if (fp == NULL) {
        printf("无法打开教室信息文件。\n");
        exit(1);
    }

    while (fscanf(fp, "%*s %d", &classrooms[numClassrooms].size) == 1) {
        classrooms[numClassrooms].id = numClassrooms + 1;
        for (int i = 0; i < 9; i++) {
            classrooms[numClassrooms].isAvailable[i] = 1;  // 初始化为可用
            classrooms[numClassrooms].reservedBy[i][0] = '\0';  // 初始化预订用户名为空字符串
        }
        numClassrooms++;
    }

    fclose(fp);
}

// 保存教室预订状态到文件
void saveClassroomStatus(Classroom *classroom) {
    char filename[10];
    sprintf(filename, "C%d.txt", classroom->id);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开教室状态文件。\n");
        exit(1);
    }

    for (int i = 0; i < 9; i++) {
        fprintf(fp, "%d %s\n", classroom->isAvailable[i], classroom->reservedBy[i]);
    }

    fclose(fp);
}

// 显示可用时间段
void displayAvailableSlots(int option) {
    int currentHour, currentMinute;
    time_t current_time;
    struct tm *tblock;

    time(&current_time);
    tblock = localtime(&current_time);

    currentHour = tblock->tm_hour;
    currentMinute = tblock->tm_min;

    printf("\n===== 可预订时间段 =====\n");
    for (int i = 0; i < 9; i++) {
        int startHour = 9 + i;
        if (option == 1 && (startHour < currentHour || (startHour == currentHour && 0 <= currentMinute && currentMinute < 50))) {
            continue;  // 如果是今天且时间段已过，则不显示
        }
        printf("%d. %02d:00 - %02d:50\n", i + 1, startHour, startHour);
    }
    printf("请选择: \n");
	printf("退出请按9");

    int slot;
    scanf("%d", &slot);

    if (slot >= 1 && slot <= 8) {
        // 假设这里已经获取到了用户输入的预期教室大小，实际应从用户输入获取，这里为简化代码直接假设为30（可修改）
        int size = 30;
        int classroomIndex = findAvailableClassroom(size);
        if (classroomIndex == -1) {
            printf("没有可用的教室！\n");
        } else {
            Classroom *selectedClassroom = &classrooms[classroomIndex];
            selectedClassroom->isAvailable[slot - 1] = 0;  // 设置该时间段为不可用
            // 假设当前登录用户为第一个账户用户，实际应根据登录情况修改
            strcpy(selectedClassroom->reservedBy[slot - 1], accounts[0].username);

            printf("您已成功预订教室 %d，时间段为：%02d:00 - %02d:50\n", selectedClassroom->id, 9 + slot - 1, 9 + slot - 1);

            saveClassroomStatus(selectedClassroom);
        }
    } else if (slot == 9) {
        // 这里可添加返回上一级菜单或退出系统的逻辑，为简化代码暂时不实现
        printf("退出选择时间段。\n");
    } else {
        printf("无效的选择，请重新输入。\n");
        displayAvailableSlots(option);
    }
}

// 查找可用教室
int findAvailableClassroom(int size) {
    for (int i = 0; i < numClassrooms; i++) {
        if (classrooms[i].size >= size && classrooms[i].isAvailable[0]) {  // 假设先查找第一个时间段可用的教室，实际可根据需求调整
            return i;
        }
    }
    return -1;
}


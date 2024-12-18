#include <stdio.h>
#include <time.h>

// 函数声明
void displayMenuDates();
void printDateOptions(const char* today, const char* tomorrow, const char* dayAfterTomorrow);
void handleDateSelection(int choice, const char* today, const char* tomorrow, const char* dayAfterTomorrow);

int main() {
    int choice;

    // 显示日期菜单
    char today[11], tomorrow[11], dayAfterTomorrow[11];
    displayMenuDates(today, tomorrow, dayAfterTomorrow);

    // 提示用户输入选择
    printf("请输入你的选择 (1-3 选择日期，4 退出): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        // 处理日期选择
        handleDateSelection(choice, today, tomorrow, dayAfterTomorrow);
        
        // 输出时间段选择提示
        printf("接下来请选择时间段:\n");
    } else if (choice == 4) {
        printf("退出预订系统。\n");
    } else {
        printf("无效的选择，请重试。\n");
    }

    return 0;
}

// 显示日期菜单的函数
void displayMenuDates(char* today, char* tomorrow, char* dayAfterTomorrow) {
    time_t currentTime;
    struct tm *localTime;

    // 获取当前时间
    time(&currentTime);
    localTime = localtime(&currentTime);

    // 获取今天的日期
    strftime(today, 11, "%Y.%m.%d", localTime);

    // 获取明天的日期
    localTime->tm_mday += 1;
    mktime(localTime); // 更新日期
    strftime(tomorrow, 11, "%Y.%m.%d", localTime);

    // 获取后天的日期
    localTime->tm_mday += 1;
    mktime(localTime); // 更新日期
    strftime(dayAfterTomorrow, 11, "%Y.%m.%d", localTime);

    // 打印日期选项
    printDateOptions(today, tomorrow, dayAfterTomorrow);
}

// 打印菜单选项的函数
void printDateOptions(const char* today, const char* tomorrow, const char* dayAfterTomorrow) {
    printf("请选择日期:\n");
    printf("1. Date (today): %s\n", today);
    printf("2. Date (tomorrow): %s\n", tomorrow);
    printf("3. Date (the day after tomorrow): %s\n", dayAfterTomorrow);
    printf("4. Exit\n");
}

// 处理日期选择的函数
void handleDateSelection(int choice, const char* today, const char* tomorrow, const char* dayAfterTomorrow) {
    switch (choice) {
        case 1:
            printf("您选择的日期是: %s\n", today);
            break;
        case 2:
            printf("您选择的日期是: %s\n", tomorrow);
            break;
        case 3:
            printf("您选择的日期是: %s\n", dayAfterTomorrow);
            break;
        default:
            // 不会达到这里，因为已经在主循环中判断
            break;
    }
}

#include "date_selection.h"
#include <stdio.h>
#include <time.h>

int selectDate(time_t *selectedDate) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    int choice;
    while (1) {
        printf("1. Date (today): %d/%d/%d\n", current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900);
        printf("2. Date (tomorrow): %d/%d/%d\n", current_time->tm_mday + 1, current_time->tm_mon + 1, current_time->tm_year + 1900);
        printf("3. Date (the day after tomorrow): %d/%d/%d\n", current_time->tm_mday + 2, current_time->tm_mon + 1, current_time->tm_year + 1900);
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        struct tm selected_tm = *current_time; // copy current_time to selected_tm

        switch (choice) {
            case 1:
                *selectedDate = mktime(&selected_tm);
            return 1;
            case 2:
                selected_tm.tm_mday += 1;
            *selectedDate = mktime(&selected_tm);
            return 1;
            case 3:
                selected_tm.tm_mday += 2;
            *selectedDate = mktime(&selected_tm);
            return 1;
            case 4:
                return 0; // Exit
            default:
                printf("-_- Invalid input! Please try again.\n"); // 提示输入错误并继续循环
        }
    }
}

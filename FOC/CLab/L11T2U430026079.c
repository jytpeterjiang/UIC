/*
=============================================
 Name: L11T2U430026079.c
 Author: Peter Jiang
 Version: 1.0
 Copyright: Your copyright notice
 Description: year, month and day
 Lab 11 Task 2
 ============================================= 
*/
#include <stdio.h>
struct date {
    int month;
    int day;
    int year;
};
// prototype
struct date findNextDay(struct date inputDate);

int main() {
    struct date date;

    printf("Input a date by the order of month, day, year: ");
    scanf("%d%d%d", &date.month, &date.day, &date.year);
    
    if (date.year <= 0) {
        printf("Warning! Year input should be positive.");
        return 0;
    }
    if (date.month < 1 || date.month > 12) {
        printf("Warning! Month input should be ranging in [1, 12].");
        return 0;
    }
    
    // check whether the date is correct
    int maxDays;
    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 ||
        date.month == 8 || date.month == 10 || date.month == 12) {
        maxDays = 31;
    } else if (date.month == 2) {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) {
            maxDays = 29; // leap year
        } else {
            maxDays = 28; // common year
        }
    } else {
        maxDays = 30;
    }

    if (date.day < 1 || date.day > maxDays) {
        printf("Warning! Date input is not real.");
        return 0;
    }

    // call the function
    struct date nextDate = findNextDay(date);
    printf("The next day of input date is %d/%d/%d.\n", nextDate.month, nextDate.day, nextDate.year);
    return 0;
}

// defination
struct date findNextDay(struct date inputDate) {
    inputDate.day++;

    int maxDays;
    if (inputDate.month == 1 || inputDate.month == 3 || inputDate.month == 5 || 
        inputDate.month == 7 || inputDate.month == 8 || inputDate.month == 10 || 
        inputDate.month == 12) {
        maxDays = 31;
    } else if (inputDate.month == 2) {
        if ((inputDate.year % 4 == 0 && inputDate.year % 100 != 0) || 
            (inputDate.year % 400 == 0)) {
            maxDays = 29; // leap year
        } else {
            maxDays = 28; // common year
        }
    } else {
        maxDays = 30;
    }
    if (inputDate.day > maxDays) {
        inputDate.day = 1;
        inputDate.month++;
        if (inputDate.month > 12) {
            inputDate.month = 1;
            inputDate.year++;
        }
    }
    return inputDate;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "auth.h"
#include "date_selection.h"
#include "timeslot_selection.h"
#include "classroom_search.h"
#include "booking_record.h"

int main() {
    // get current time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    // print current time
    printf("Current time: %02d:%02d:%02d on %02d/%02d/%d\n",
           current_time->tm_hour, current_time->tm_min, current_time->tm_sec,
           current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900);

    char username[50], password[50];
    int loginAttempts = 0;

    printf("^_^ Welcome to the classroom booking system!\n");

    while (loginAttempts < 3) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (authenticateUser(username, password)) {
            printf("~OwO~ Welcome %s!\n",username);
            break;
        } else {
            printf("-_- Invalid account name or password!\n");
            loginAttempts++;
        }
    }

    if (loginAttempts == 3) {
        printf("T_T You have failed three times!\n");
        return 1;
    }

    bool continueBooking = true;
    while (continueBooking) {
        time_t selectedDate;
        if (selectDate(&selectedDate) == 0) {
            printf("OwO~bye Exiting...\n");
            return 0;
        }

        int timeslot = selectTimeslot(selectedDate);
        if (timeslot == -3) {
            printf("T_T No available timeslot for the selected date. Please choose another date.\n");
            continue; // Go back to date selection
        } else if (timeslot == -2){
            printf("OwO~ Back to menu.\n");
            continue;
        }else if (timeslot == -1){
            printf("-_-Invalid input. Please try again.\n");
            continue;
        }else if (timeslot == 0){
            printf("OwO~bye~ Exiting...\n");
            return 0; // Exit the program
        }

        int requiredSize;
        printf("Input the size of classroom: ");
        scanf("%d", &requiredSize);

        char *classroom = findAvailableClassroom(requiredSize, timeslot, selectedDate);
        if (classroom) {
            printf("^_^ Classroom %s is available.\n", classroom);
            recordBooking(classroom, timeslot, username, selectedDate);
            free(classroom);
        } else {
            printf("T_T No available room for the selected timeslot and date!\n");
            continue; // Go back to date selection
        }

        char continueChoice;
        printf("OwO~ Continue (y/n)? ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y') {
            continueBooking = false;
        }
    }

    printf("OwO~bye~ Exiting...\n");
    return 0;
}

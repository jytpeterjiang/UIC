#include "timeslot_selection.h"
#include <stdio.h>
#include <time.h>
#include <string.h> // used for memcpy

int selectTimeslot(time_t selectedDate) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    struct tm current_tm;

    if (!current_time) {
        printf("T_T Failed to get current time.\n");
        return -1;
    }

    // copy current_time to current_tm
    memcpy(&current_tm, current_time, sizeof(struct tm));

    struct tm *temp_selected_tm = localtime(&selectedDate);
    struct tm selected_tm;

    if (!temp_selected_tm) {
        printf("T_T Invalid date selected.\n");
        return -1;
    }

    // copy temp_selected_tm to selected_tm
    memcpy(&selected_tm, temp_selected_tm, sizeof(struct tm));

    int start_hour = 9;
    int end_hour = 17;

    // Check if selectedDate is today
    if (selected_tm.tm_year == current_tm.tm_year &&
        selected_tm.tm_mon == current_tm.tm_mon &&
        selected_tm.tm_mday == current_tm.tm_mday) {
        // If selectedDate is today, adjust start_hour based on current time
        if (current_tm.tm_hour >= 17) {
            //printf("No available timeslots for today. Please choose another date.\n");
            return -3;
        }
        start_hour = current_tm.tm_hour + 1;
    }

    int num_timeslots = end_hour - start_hour;

    // add debug infomation
    //printf("Debug: start_hour = %d, end_hour = %d, num_timeslots = %d\n", start_hour, end_hour, num_timeslots);
    /*
    if (num_timeslots <= 0) {
        return -3;
    }
    */
    // before 9:00
	if (num_timeslots >= 8) {
		start_hour = 9;// change start hour to 9:00
		num_timeslots = 8;
	}

    printf("===Available timeslots===\n");
    for (int i = 0; i < num_timeslots; ++i) {
        printf("%d. %02d:00 - %02d:50\n", i + 1, start_hour + i, start_hour + i);
    }
    printf("%d. Back\n", num_timeslots + 1);
    printf("%d. Exit\n", num_timeslots + 2);

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_timeslots) {
        return start_hour + choice - 1;
    } else if (choice == num_timeslots + 1) {
        return -2; // Back
    }else if (choice == num_timeslots + 2){
        return 0; // Exit
    }else {
        return -1;
    }
}

#include "booking_record.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void recordBooking(const char *classroom, int timeslot, const char *username, time_t selectedDate) {
    char filename[50];
    snprintf(filename, sizeof(filename), "%s_bookings.txt", classroom);

    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("T_T Failed to open booking file");
        return;
    }

    struct tm *selected_tm = localtime(&selectedDate);

    fprintf(file, "Date: %d/%d/%d, Timeslot: %02d:00-%02d:50, User: %s\n",
            selected_tm->tm_mday, selected_tm->tm_mon + 1, selected_tm->tm_year + 1900,
            timeslot, timeslot, username);

    fclose(file);
}

#include "booking_record.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isClassroomBooked(const char *classroom, int timeslot, time_t selectedDate) {
    char filename[50];
    snprintf(filename, sizeof(filename), "%s_bookings.txt", classroom);

    FILE *file = fopen(filename, "r");
    if (!file) {
        return false; // File does not exist, so no bookings
    }

    char line[100];
    char dateStr[20];
    struct tm *selected_tm = localtime(&selectedDate);

    // Format the selected date as "Day/Month/Year"
    snprintf(dateStr, sizeof(dateStr), "%02d/%02d/%04d",
             selected_tm->tm_mday, selected_tm->tm_mon + 1, selected_tm->tm_year + 1900);

    while (fgets(line, sizeof(line), file)) {
        char booked_date[20];
        int booked_timeslot;

        // Check if the line contains the date
        if (sscanf(line, "Date: %19[^,]", booked_date) == 1) {
            // Check if the date matches
            if (strcmp(booked_date, dateStr) == 0) {
                // Check if the line contains the timeslot
                if (sscanf(line, "Date: %*[^,], Timeslot: %02d:00-%02d:50", &booked_timeslot, &booked_timeslot) == 2) {
                    if (booked_timeslot == timeslot) {
                        fclose(file);
                        return true; // Classroom is booked at this timeslot
                    }
                }
            }
        }
    }

    fclose(file);
    return false; // Classroom is not booked at this timeslot
}
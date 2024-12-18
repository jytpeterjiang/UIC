#include "classroom_search.h"
#include <stdio.h>
#include <string.h>
#include "booking_record.h" // Include booking_record.h to use isClassroomBooked
#include <stdlib.h>

char* findAvailableClassroom(int requiredSize, int timeslot, time_t selectedDate) {
    FILE *file = fopen("classroom_info.txt", "r");
    if (!file) {
        perror("T_T Failed to open classroom_info.txt");
        return NULL;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char classroom[10];
        int size;
        sscanf(line, "%s %d", classroom, &size);
        if (size >= requiredSize) {
            if (!isClassroomBooked(classroom, timeslot, selectedDate)) {
                fclose(file);
                return _strdup(classroom);
            }
        }
    }

    fclose(file);
    return NULL;
}

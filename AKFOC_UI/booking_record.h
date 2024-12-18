#ifndef AKFOC_BOOKING_RECORD_H
#define AKFOC_BOOKING_RECORD_H
#include <time.h>
#include <stdbool.h>

void recordBooking(const char *classroom, int timeslot, const char *username, time_t selectedDate);
bool isClassroomBooked(const char *classroom, int timeslot, time_t selectedDate);

#endif // AKFOC_BOOKING_RECORD_H

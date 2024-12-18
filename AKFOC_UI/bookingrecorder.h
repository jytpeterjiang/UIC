// bookingrecorder.h
#ifndef BOOKINGRECORDER_H
#define BOOKINGRECORDER_H

#include <QString>
#include <time.h>

class BookingRecorder {
public:
    void recordBooking(const char *classroom, int timeslot, const char *username, time_t selectedDate);
    bool isClassroomBooked(const char *classroom, int timeslot, time_t selectedDate);
};

#endif // BOOKINGRECORDER_H

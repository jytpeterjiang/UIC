// classroomsearcher.h
#ifndef CLASSROOMSEARCHER_H
#define CLASSROOMSEARCHER_H

#include <QString>

class ClassroomSearcher {
public:
    char* findAvailableClassroom(int requiredSize, int timeslot, time_t selectedDate);
};

#endif // CLASSROOMSEARCHER_H

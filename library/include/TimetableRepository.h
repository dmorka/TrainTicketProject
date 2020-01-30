#ifndef TRAINTICKETPROJECT_TIMETABLEREPOSITORY_H
#define TRAINTICKETPROJECT_TIMETABLEREPOSITORY_H

#include <memory>
#include "Repository.h"
#include "Timetable.h"

class TimetableRepository : public Repository<Timetable>
{};

typedef shared_ptr<TimetableRepository> TimetableRepositoryPtr;

#endif //TRAINTICKETPROJECT_TIMETABLEREPOSITORY_H
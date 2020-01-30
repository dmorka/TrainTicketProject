#ifndef TRAINTICKETPROJECT_TIMETABLE_H
#define TRAINTICKETPROJECT_TIMETABLE_H

#include <string>
#include <iomanip>
#include <memory>
#include <boost/date_time/local_time/local_date_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include "boost/date_time/time_zone_base.hpp"
#include <boost/uuid/random_generator.hpp>
#include "Route.h"
#include "Train.h"
#include "ParameterException.h"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

typedef shared_ptr<local_date_time> localDateTimePtr;

class Timetable{
private:
    uuid timetableID;
    localDateTimePtr startTime;
    localDateTimePtr endTime;
    RoutePtr route;
    TrainPtr train;

public:
    Timetable(TrainPtr train, RoutePtr route, localDateTimePtr startTime, localDateTimePtr endTime);

    ~Timetable();

    uuid getID() const;

    const TrainPtr &getTrain() const;

    const RoutePtr &getRoute() const;

    string getInfo();

    void setTrain(const TrainPtr &train);

    void setRoute(const RoutePtr &route);

    const localDateTimePtr &getStartTime() const;

    const localDateTimePtr &getEndTime() const;

    void setStartTime(const localDateTimePtr &startTime);

    void setEndTime(const localDateTimePtr &endTime);

    double getDuration();

    bool operator==(const Timetable &rhs) const;

    bool operator!=(const Timetable &rhs) const;
};

typedef shared_ptr<Timetable> TimetablePtr;

#endif //TRAINTICKETPROJECT_TIMETABLE_H
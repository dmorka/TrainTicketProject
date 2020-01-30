#include <boost/shared_ptr.hpp>
#include <Timetable.h>
#include <boost/date_time/local_time/local_time.hpp>

Timetable::Timetable(TrainPtr train, RoutePtr route, localDateTimePtr startTime, localDateTimePtr endTime)
        : train(train), route(route), startTime(startTime), endTime(endTime), timetableID(boost::uuids::random_generator()())
{
    if(train == nullptr)
    {
        throw ParameterException("Error! Train is required");
    }
    if(startTime == nullptr)
    {
        throw ParameterException("Error! Start time is required");
    }
    if(route == nullptr)
    {
        throw ParameterException("Error! Route is required");
    }
    if(endTime == nullptr)
    {
        throw ParameterException("Error! End time is required");
    }
}

Timetable::~Timetable() = default;

string Timetable::getInfo()
{
    stringstream info;
    info << "Trasa " << this->getRoute()->getStartPoint() << " - " << this->getRoute()->getEndPoint() << ". Start o godzinie " << *this->getStartTime() << ", koniec trasy o godzinie " << *this->getEndTime() << ". Trase pokona pociag" << this->getTrain()->getID() << ".";
    return info.str();
}

double Timetable::getDuration()
{
    double dur=0.00;
    local_time_period duration(*startTime, *endTime);
    dur = duration.length().hours() + 0.01*(duration.length().minutes());
    return dur;
}

uuid Timetable::getID() const
{
    return timetableID;
}

const shared_ptr<local_date_time_base<>> &Timetable::getStartTime() const
{
    return startTime;
}

const shared_ptr<local_date_time_base<>> &Timetable::getEndTime() const
{
    return endTime;
}

const RoutePtr &Timetable::getRoute() const
{
    return route;
}

const TrainPtr &Timetable::getTrain() const
{
    return train;
}

void Timetable::setStartTime(const localDateTimePtr &startTime)
{
    if(startTime == nullptr)
    {
        throw ParameterException("Error! Start time can't be nullptr");
    }
    Timetable::startTime = startTime;
}

void Timetable::setEndTime(const localDateTimePtr &endTime)
{
    if(endTime == nullptr)
    {
        throw ParameterException("Error! End time can't be nullptr");
    }
    Timetable::endTime = endTime;
}

void Timetable::setRoute(const RoutePtr &route)
{
    if(route == nullptr)
    {
        throw ParameterException("Error! Route can't be nullptr");
    }
    Timetable::route = route;
}

void Timetable::setTrain(const TrainPtr &train)
{
    if(train == nullptr)
    {
        throw ParameterException("Error! Train can't be nullptr");
    }
    Timetable::train = train;
}

bool Timetable::operator==(const Timetable &rhs) const
{
    return timetableID == rhs.timetableID &&
           *startTime == *rhs.startTime &&
           *endTime == *rhs.endTime &&
           *route == *rhs.route &&
           *train == *rhs.train;
}

bool Timetable::operator!=(const Timetable &rhs) const
{
    return !(rhs == *this);
}

#ifndef TRAINTICKETPROJECT_TICKET_H
#define TRAINTICKETPROJECT_TICKET_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include "boost/date_time/time_zone_base.hpp"
#include <memory>
#include "TravelClass.h"
#include "Route.h"
#include "Train.h"
#include "Client.h"
#include "ParameterException.h"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;

typedef shared_ptr<local_date_time> localDateTimePtr;

class Ticket {
private:
    uuid ticketID;
    localDateTimePtr dateOfPurchase;
    double price;
    int seat;
    localDateTimePtr startTime;
    localDateTimePtr endTime;
    ClientPtr client;
    TrainPtr train;
    RoutePtr route;
    TravelClass ticketClass;

public:
    Ticket(TravelClass ticketClass, ClientPtr client, TrainPtr train, RoutePtr route, double pricePerKM, localDateTimePtr startTime, localDateTimePtr endTime);

    ~Ticket();

    uuid getID() const;

    double getPrice() const;

    const localDateTimePtr &getDateOfPurchase() const;

    int getSeat() const;

    string getInfo(bool showClientInfo=0) const;

    TravelClass getTicketClass() const;

    void setTicketClass(TravelClass ticketClass);

    const localDateTimePtr &getStartTime() const;

    const localDateTimePtr &getEndTime() const;

    const ClientPtr &getClient() const;

    const TrainPtr &getTrain() const;

    const RoutePtr &getRoute() const;

    bool operator==(const Ticket &rhs) const;

    bool operator!=(const Ticket &rhs) const;
};

typedef shared_ptr<Ticket> TicketPtr;

#endif //TRAINTICKETPROJECT_TICKET_H
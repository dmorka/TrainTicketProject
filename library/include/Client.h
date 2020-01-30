#ifndef TRAINTICKETPROJECT_CLIENT_H
#define TRAINTICKETPROJECT_CLIENT_H

#include <string>
#include <memory>
#include <boost/date_time/local_time/local_time.hpp>
#include "boost/date_time/time_zone_base.hpp"
#include "ClientType.h"
#include "BasicClient.h"
#include "StudentClient.h"
#include "PensionerClient.h"
#include "ParameterException.h"

using namespace boost::local_time;
using namespace boost::gregorian;
using namespace boost::posix_time;

class Ticket;

typedef shared_ptr<Ticket> TicketPtr;
typedef shared_ptr<local_date_time> localDateTimePtr;

class Client;
typedef shared_ptr<Client> ClientPtr;

class Client
{
private:
    string personalID;
    string firstName;
    string lastName;
    localDateTimePtr dateOfBirth;
    ClientTypePtr clientType;
    vector<TicketPtr> tickets;

public:
    Client(string personalID, string firstName, string lastName, localDateTimePtr dateOfBirth);

    ~Client();

    const string &getFirstName() const;

    const string &getLastName() const;

    string getID() const;

    const localDateTimePtr &getDateOfBirth() const;

    int getAge() const;

    const vector<TicketPtr> &getTickets() const;

    string getInfo(bool showTickets=0) const;

    const ClientTypePtr &getClientType() const;

    void addTicket(TicketPtr ticket) ;

    void removeTicket(TicketPtr ticket);

    void setClientType();

    bool operator==(const Client &rhs) const;

    bool operator!=(const Client &rhs) const;
};

#endif //TRAINTICKETPROJECT_CLIENT_H
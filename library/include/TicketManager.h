#ifndef TRAINTICKETPROJECT_TICKETMANAGER_H
#define TRAINTICKETPROJECT_TICKETMANAGER_H

#include "TicketRepository.h"
#include "TimetableRepository.h"

class TicketManager {
private:
    TicketRepositoryPtr ticket;
    TimetableRepositoryPtr timetable;
    void changeClientType(ClientPtr &client);

public:
    TicketManager(TicketRepositoryPtr ticket, TimetableRepositoryPtr timetable);

    virtual ~TicketManager();

    bool buyTicket(ClientPtr client, TimetablePtr timetable, TravelClass ticketClass, double pricePerKM=0.5);

    bool cancelTicket(TicketPtr ticket);

    string getTicketsInfo();

    bool createTimetable(TimetablePtr timetable);

    bool removeTimetable(TimetablePtr timetable);

    bool clearTimetable();

    string getTimetableInfo();

    TicketPtr operator()(const string &ticketID);
};

typedef shared_ptr<TicketManager> TicketManagerPtr;

#endif //TRAINTICKETPROJECT_TICKETMANAGER_H
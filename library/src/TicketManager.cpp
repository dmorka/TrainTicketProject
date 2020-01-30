#include <boost/shared_ptr.hpp>
#include <TicketManager.h>

TicketManager::TicketManager(TicketRepositoryPtr ticket, TimetableRepositoryPtr timetable)
        : ticket(ticket), timetable(timetable)
{
    if(ticket == nullptr)
    {
        throw ParameterException("Error! Ticket Repository required");
    }
    if(timetable == nullptr)
    {
        throw ParameterException("Error! Timetable Repository required");
    }
}

TicketManager::~TicketManager() = default;

void TicketManager::changeClientType(ClientPtr &client)
{
    client->setClientType();
}

bool TicketManager::buyTicket(ClientPtr client, TimetablePtr timetable, TravelClass ticketClass, double pricePerKM)
{
    changeClientType(client);
    TicketPtr ticket(new Ticket(ticketClass, client, timetable->getTrain(), timetable->getRoute(), 0.5, timetable->getStartTime(), timetable->getEndTime()));
    ticket->getClient()->addTicket(ticket);
    return this->ticket->create(ticket);
}

bool TicketManager::cancelTicket(TicketPtr ticket)
{
    ticket->getClient()->removeTicket(ticket);
    return this->ticket->remove(ticket);
}

bool TicketManager::createTimetable(TimetablePtr timetable)
{
    return this->timetable->create(timetable);
}

bool TicketManager::removeTimetable(TimetablePtr timetable)
{
    return this->timetable->remove(timetable);
}

bool TicketManager::clearTimetable()
{
    return this->timetable->clear();
}

string TicketManager::getTimetableInfo()
{
    return this->timetable->getInfo();
}

string TicketManager::getTicketsInfo()
{
    return this->ticket->getInfo();
}

TicketPtr TicketManager::operator()(const string &ticketID)
{
    return ticket->find(ticketID);
}
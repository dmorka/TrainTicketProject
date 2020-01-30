#ifndef TRAINTICKETPROJECT_TICKETREPOSITORY_H
#define TRAINTICKETPROJECT_TICKETREPOSITORY_H

#include <memory>
#include "Repository.h"
#include "Ticket.h"

class TicketRepository : public Repository<Ticket>
{};

typedef shared_ptr<TicketRepository> TicketRepositoryPtr;

#endif //TRAINTICKETPROJECT_TICKETREPOSITORY_H
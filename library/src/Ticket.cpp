#include "Ticket.h"

Ticket::Ticket(TravelClass ticketClass, ClientPtr client, TrainPtr train, RoutePtr route, double pricePerKM, localDateTimePtr startTime, localDateTimePtr endTime)
        : ticketClass(ticketClass), client(client), train(train), route(route), startTime(startTime), endTime(endTime), ticketID(random_generator()())
{
    if(client == nullptr)
    {
        throw ParameterException("Error! Client required");
    }
    if(train == nullptr)
    {
        throw ParameterException("Error! Train required");
    }
    if(route == nullptr)
    {
        throw ParameterException("Error! Route required");
    }
    if(startTime == nullptr)
    {
        throw ParameterException("Error! Start time required");
    }
    if(endTime == nullptr)
    {
        throw ParameterException("Error! End time required");
    }
    if(pricePerKM <= 0)
    {
        throw ParameterException("Error! Price per km must be positive");
    }
    //Zapisanie daty i godziny kupienia biletu
    time_zone_ptr zone(new posix_time_zone("CET+1"));
    dateOfPurchase = localDateTimePtr(new local_date_time(local_sec_clock::local_time(zone)));

    //Wyliczanie ceny biletu
    double surcharge = (ticketClass == FirstClass) ? 1.5 : 1;
    price =  client->getClientType()->countDiscount((route->getLength() * pricePerKM) * surcharge);

    //Przypisanie pierwszego wolnego miejsca w wagonie o określonej klasie
    seat = train->bookSeat(ticketClass);
}

Ticket::~Ticket() = default;

uuid Ticket::getID() const
{
    return ticketID;
}

const localDateTimePtr &Ticket::getDateOfPurchase() const
{
    return dateOfPurchase;
}

double Ticket::getPrice() const
{
    return price;
}

int Ticket::getSeat() const
{
    return seat;
}

const localDateTimePtr &Ticket::getStartTime() const
{
    return startTime;
}

const localDateTimePtr &Ticket::getEndTime() const
{
    return endTime;
}

const ClientPtr &Ticket::getClient() const
{
    return client;
}

const TrainPtr &Ticket::getTrain() const
{
    return train;
}

const RoutePtr &Ticket::getRoute() const
{
    return route;
}

TravelClass Ticket::getTicketClass() const
{
    return ticketClass;
}

void Ticket::setTicketClass(TravelClass ticketClass)
{
    Ticket::ticketClass = ticketClass;
}

string Ticket::getInfo(bool showClientInfo) const
{
    stringstream info;
    info << "Bilet ID: " << ticketID << "Klasa biletu: " << ticketClass << " Data zakupu: " << *dateOfPurchase << " Cena: " << price << " Miejsce: " << seat
         << " Pociąg: " << train->getName() << " " << train->getID() << " " << route->getInfo() << " Czas odjazdu: " << *startTime << " Czas dojazdu: " << *endTime;
    if(showClientInfo)
    {
        info << " Klient: " << client->getInfo(false);
    }

    return info.str();
}

bool Ticket::operator==(const Ticket &rhs) const
{
    return ticketID == rhs.ticketID &&
           *dateOfPurchase == *rhs.dateOfPurchase &&
           price == rhs.price &&
           seat == rhs.seat &&
           *startTime == *rhs.startTime &&
           *endTime == *rhs.endTime &&
           *train == *rhs.train &&
           *route == *rhs.route &&
           ticketClass == rhs.ticketClass;
}

bool Ticket::operator!=(const Ticket &rhs) const
{
    return !(rhs == *this);
}

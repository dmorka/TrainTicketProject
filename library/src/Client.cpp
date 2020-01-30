#include "Client.h"
#include "Ticket.h"

Client::Client(string personalID, string firstName, string lastName, localDateTimePtr dateOfBirth)
        : personalID(personalID), firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth)
{
    if(firstName == "")
    {
        throw ParameterException("Error! First name is required");
    }
    if(lastName == "")
    {
        throw ParameterException("Error! Last name is required");
    }
    if(personalID == "")
    {
        throw ParameterException("Error! Personal ID is required");
    }
    if(dateOfBirth == nullptr)
    {
        throw ParameterException("Error! Date of birth is required");
    }

    setClientType();
}

Client::~Client()
{}

string Client::getID() const
{
    return personalID;
}

const string &Client::getFirstName() const
{
    return firstName;
}

const string &Client::getLastName() const
{
    return lastName;
}

const localDateTimePtr &Client::getDateOfBirth() const
{
    return dateOfBirth;
}

const ClientTypePtr &Client::getClientType() const
{
    return clientType;
}

const vector<TicketPtr> &Client::getTickets() const
{
    return tickets;
}

int Client::getAge() const
{
    time_zone_ptr zone(new posix_time_zone("CET+1"));
    localDateTimePtr current(new local_date_time(local_sec_clock::local_time(zone)));
    local_time_period dur(*dateOfBirth, *current);
    return dur.length().hours()/(24*365);
}

string Client::getInfo(bool showTickets) const
{
    stringstream info;
    info <<"Pesel: "<<personalID<< " Imie: " << firstName << " Nazwisko: "<< lastName<<" Data urodzenia: "<<*dateOfBirth<<" Typ: "<<clientType->getTypeName();
    if(showTickets)
    {
        info<<endl<<"Tickets: "<<endl;
        for(auto el : this->tickets)
        {
            info << el->getInfo(false)<<endl;
        }
    }
    return info.str();
}

void Client::addTicket(TicketPtr ticket)
{
    tickets.push_back(ticket);
}

void Client::removeTicket(TicketPtr ticket)
{
    int z = 0;
    for(auto el : this->tickets)
    {
        if(*el == *ticket)
        {
            tickets.erase(this->tickets.begin()+z);
            return;
        }
        z++;
    }
    throw AvailableException("Error! Ticket not found");
}

void Client::setClientType()
{
    if(this->getAge() <= 26)
    {
        clientType = ClientTypePtr(new StudentClient());
    }
    else if(this->getAge() <= 67)
    {
        clientType = ClientTypePtr(new BasicClient());
    }
    else
    {
        clientType = ClientTypePtr(new PensionerClient());
    }
}

bool Client::operator==(const Client &rhs) const
{
    if( personalID != rhs.personalID || firstName != rhs.firstName || lastName != rhs.lastName || *dateOfBirth != *rhs.dateOfBirth)
    {
        return false;
    }

    for(int i = 0; i < tickets.size(); i++)
    {
        if(*tickets[i] != *rhs.tickets[i])
        {
            return false;
        }
    }
    return true;
}

bool Client::operator!=(const Client &rhs) const
{
    return !(rhs == *this);
}

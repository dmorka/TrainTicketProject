#include <Carriage.h>
#include <sstream>

Carriage::Carriage(int numberOfSeats, const TravelClass &carriageClass)
        : numberOfSeats(numberOfSeats), carriageClass(carriageClass)
{
    if(numberOfSeats < 30)
    {
        throw ParameterException("Error! Number of seats < 30");
    }

    freeSeats = new bool[numberOfSeats];

    for(int i = 0; i < numberOfSeats; i++)
    {
        freeSeats[i] = false;
    };
}

Carriage::~Carriage()
{
    delete[] freeSeats;
}

int Carriage::getNumberOfSeats() const
{
    return numberOfSeats;
}

bool *Carriage::getFreeSeats() const
{
    return freeSeats;
}

const TravelClass &Carriage::getCarriageClass() const
{
    return carriageClass;
}

string Carriage::getInfo()
{
    stringstream info;
    info<<"Wagon klasy "<<this->getCarriageClass()<<" posiada "<<this->getNumberOfSeats()<<" miejsc.";
    return info.str();
}

void Carriage::setFreeSeat(int index, bool value)
{
    if(index  < 0 || index >= numberOfSeats)
    {
        throw AvailableException("Error! Seat not found");
    }
    this->getFreeSeats()[index] = value ? 1 : 0;
}

bool Carriage::operator==(const Carriage &rhs) const
{
    if(numberOfSeats != rhs.numberOfSeats || carriageClass != rhs.carriageClass)
    {
        return false;
    }

    for(int i = 0; i < numberOfSeats; i++)
    {
        if(freeSeats[i] != rhs.freeSeats[i])
        {
            return false;
        }
    }

    return true;
}

bool Carriage::operator!=(const Carriage &rhs) const
{
    return !(rhs == *this);
}

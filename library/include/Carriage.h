#ifndef TRAINTICKETPROJECT_CARRIAGE_H
#define TRAINTICKETPROJECT_CARRIAGE_H

#include <memory>
#include "TravelClass.h"
#include "ParameterException.h"
#include "AvailableException.h"

class Carriage
{
private:
    int numberOfSeats;
    bool *freeSeats = new bool[numberOfSeats];
    TravelClass carriageClass;

public:
    Carriage(int numberOfSeats, const TravelClass &carriageClass);

    ~Carriage();

    const TravelClass &getCarriageClass() const;

    int getNumberOfSeats() const;

    bool *getFreeSeats() const;

    string getInfo();

    void setFreeSeat(int index, bool value);

    bool operator==(const Carriage &rhs) const;

    bool operator!=(const Carriage &rhs) const;
};

typedef shared_ptr<Carriage> CarriagePtr;

#endif //TRAINTICKETPROJECT_CARRIAGE_H
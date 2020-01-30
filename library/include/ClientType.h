#ifndef TRAINTICKETPROJECT_CLIENTTYPE_H
#define TRAINTICKETPROJECT_CLIENTTYPE_H

#include <memory>
#include "ParameterException.h"

class ClientType
{
private:
    double discount;
    int maxAge;

public:
    ClientType(double discount, int maxAge);

    virtual ~ClientType();

    double getDiscount() const;

    int getMaxAge() const;

    virtual double countDiscount(double price);

    virtual string getTypeName() const;
};

typedef shared_ptr<ClientType> ClientTypePtr;

#endif //TRAINTICKETPROJECT_CLIENTTYPE_H
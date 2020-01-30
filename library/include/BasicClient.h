#ifndef TRAINTICKETPROJECT_BASICCLIENT_H
#define TRAINTICKETPROJECT_BASICCLIENT_H

#include "ClientType.h"

class BasicClient : public ClientType
{
public:
    BasicClient();

    ~BasicClient();

    string getTypeName() const;

    double countDiscount(double price) const;
};

#endif //TRAINTICKETPROJECT_BASICCLIENT_H
#ifndef TRAINTICKETPROJECT_STUDENTCLIENT_H
#define TRAINTICKETPROJECT_STUDENTCLIENT_H

#include "ClientType.h"

class StudentClient : public ClientType
{
public:
    StudentClient();

    ~StudentClient();

    string getTypeName() const;

    double countDiscount(double price) const;
};

#endif //TRAINTICKETPROJECT_STUDENTCLIENT_H
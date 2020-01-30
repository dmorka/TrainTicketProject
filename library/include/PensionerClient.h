#ifndef TRAINTICKETPROJECT_PENSIONERCLIENT_H
#define TRAINTICKETPROJECT_PENSIONERCLIENT_H

#include "ClientType.h"

class PensionerClient : public ClientType
{
public:
    PensionerClient();

    ~PensionerClient();

    string getTypeName() const;

    double countDiscount(double price) const;
};

#endif //TRAINTICKETPROJECT_PENSIONERCLIENT_H
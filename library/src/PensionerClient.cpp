#include "PensionerClient.h"

PensionerClient::PensionerClient()
        : ClientType(0.7,150)
{}

PensionerClient::~PensionerClient() = default;

double PensionerClient::countDiscount(double price) const
{
    return price * ClientType::getDiscount();
}

string PensionerClient::getTypeName() const
{
    return "Senior";
}
#include "ClientType.h"

ClientType::ClientType(double discount, int maxAge)
        : discount(discount), maxAge(maxAge)
{
    if(discount < 0)
    {
        throw ParameterException("Error! Discount must be non-negative");
    }
    if(maxAge <= 0)
    {
        throw ParameterException("Error! Max age must be positive");
    }
}

ClientType::~ClientType() = default;

int ClientType::getMaxAge() const
{
    return maxAge;
}

double ClientType::getDiscount() const
{
    return discount;
}

double ClientType::countDiscount(double price)
{
    return price;
}

string ClientType::getTypeName() const
{
    return "";
}
#include "BasicClient.h"

BasicClient::BasicClient()
        : ClientType(1.0, 67)
{}

BasicClient::~BasicClient() = default;

double BasicClient::countDiscount(double price) const
{
    return price;
}

string BasicClient::getTypeName() const
{
    return "Podstawowy";
}
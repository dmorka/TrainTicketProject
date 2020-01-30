#include "StudentClient.h"
#include "cmath"

StudentClient::StudentClient()
        : ClientType(0.5,26)
{}

StudentClient::~StudentClient() = default;

double StudentClient::countDiscount(double price) const
{
    return round((price * ClientType::getDiscount() + 0.005) * 100.0) / 100.0;
}

string StudentClient::getTypeName() const
{
    return "Student";
}
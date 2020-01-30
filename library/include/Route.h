#ifndef TRAINTICKETPROJECT_ROUTE_H
#define TRAINTICKETPROJECT_ROUTE_H

#include <string>
#include <sstream>
#include <memory>
#include "ParameterException.h"

using namespace std;

class Route
{
private:
    int length;
    string startPoint;
    string endPoint;

public:
    Route(int length, const string &startPoint, const string &endPoint);

    ~Route();

    int getLength() const;

    const string &getStartPoint() const;

    const string &getEndPoint() const;

    string getInfo();

    bool operator==(const Route &rhs) const;

    bool operator!=(const Route &rhs) const;
};

typedef shared_ptr<Route> RoutePtr;

#endif //TRAINTICKETPROJECT_ROUTE_H
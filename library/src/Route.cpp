#include <Route.h>

Route::Route(int length, const string &startPoint, const string &endPoint)
        : length(length), startPoint(startPoint), endPoint(endPoint)
{
    if(length <= 0)
    {
        throw ParameterException("Error! Length must be positive");
    }
    if(startPoint == "")
    {
        throw ParameterException("Error! Start point is required");
    }
    if(endPoint == "")
    {
        throw ParameterException("Error! End point is required");
    }
}

Route::~Route() = default;

int Route::getLength() const
{
    return length;
}

const string &Route::getStartPoint() const
{
    return startPoint;
}

const string &Route::getEndPoint() const
{
    return endPoint;
}

string Route::getInfo()
{
    stringstream info;
    info<<"Trasa "<<this->startPoint<<" - "<<this->endPoint<<". Dlugosc: "<<this->length<<" km.";
    return info.str();
}

bool Route::operator==(const Route &rhs) const
{
    return length == rhs.length &&
           startPoint == rhs.startPoint &&
           endPoint == rhs.endPoint;
}

bool Route::operator!=(const Route &rhs) const
{
    return !(rhs == *this);
}

#ifndef TRAINTICKETPROJECT_AVAILABLEEXCEPTION_H
#define TRAINTICKETPROJECT_AVAILABLEEXCEPTION_H

#include <stdexcept>

using namespace std;

class AvailableException : public logic_error
{
public:
    explicit AvailableException(string arg);
};

#endif //TRAINTICKETPROJECT_AVAILABLEEXCEPTION_H
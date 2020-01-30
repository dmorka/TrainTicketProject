#ifndef TRAINTICKETPROJECT_PARAMETEREXCEPTION_H
#define TRAINTICKETPROJECT_PARAMETEREXCEPTION_H

#include <stdexcept>

using namespace std;

class ParameterException : public logic_error
{
public:
    explicit ParameterException(string arg);
};

#endif //TRAINTICKETPROJECT_PARAMETEREXCEPTION_H
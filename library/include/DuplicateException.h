#ifndef TRAINTICKETPROJECT_DUPLICATEEXCEPTION_H
#define TRAINTICKETPROJECT_DUPLICATEEXCEPTION_H

#include <stdexcept>

using namespace std;

class DuplicateException : public logic_error
{
public:
    explicit DuplicateException(string arg);
};

#endif //TRAINTICKETPROJECT_DUPLICATEEXCEPTION_H
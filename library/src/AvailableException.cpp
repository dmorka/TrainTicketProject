#include <AvailableException.h>

AvailableException::AvailableException(string arg)
        : std::logic_error(arg)
{}
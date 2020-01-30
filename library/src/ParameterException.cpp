#include "ParameterException.h"

ParameterException::ParameterException(std::string arg)
        : std::logic_error(arg)
{}
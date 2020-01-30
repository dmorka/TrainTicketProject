#include <DuplicateException.h>

DuplicateException::DuplicateException(std::string arg)
        : std::logic_error(arg)
{}
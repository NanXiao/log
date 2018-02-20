#include "log.h"

void log(std::ostream& out, std::stringstream& ss)
{
    out << ss.str();
    return;
}
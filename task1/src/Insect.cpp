#include <string>
#include "Insect.hpp"

Insect::Insect()
{
    _unique = "всеядный";
};

Insect::~Insect()
{
    //
};

const std::string Insect::getUnique()
{
    std::string buf;
    buf = "Питание: " + _unique;
    return buf;
};


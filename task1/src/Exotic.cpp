#include <string>
#include "Exotic.hpp"

Exotic::Exotic()
{
    _unique = "в основном безвреден";
};

Exotic::~Exotic()
{
    //
};

const std::string Exotic::getUnique()
{
    std::string buf;
    buf = "Примечание: " + _unique;
    return buf;
};


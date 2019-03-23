#include <string>
#include "Fish.hpp"

Fish::Fish()
{
    _unique = "не имеет значения";
};

Fish::~Fish()
{
    //
};

const std::string Fish::getUnique()
{
    std::string buf;
    buf = "Требуемая вода: " + _unique;
    return buf;
};


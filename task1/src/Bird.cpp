#include <string>
#include "Bird.hpp"

Bird::Bird()
{
    _unique = "молчаливая";
};

Bird::~Bird()
{
    //
};

const std::string Bird::getUnique()
{
    std::string buf;
    buf = "Голос: " + _unique;
    return buf;
};


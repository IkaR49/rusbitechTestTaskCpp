#include <string>
#include "Reptile.hpp"

Reptile::Reptile()
{
    _unique = "не имеет значения";
};

Reptile::~Reptile()
{
    //
};

const std::string Reptile::getUnique()
{
    std::string buf;
    buf = "Среда обитания: " + _unique;
    return buf;
};


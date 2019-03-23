#include <string>
#include "Mammal.hpp"

Mammal::Mammal()
{
    _unique = "нет особых требований";
};

Mammal::~Mammal()
{
    //
};

const std::string Mammal::getUnique()
{
    std::string buf;
    buf = "Условия содержания: " + _unique;
    return buf;
};


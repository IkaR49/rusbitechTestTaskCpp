#include <string>
#include "Amphibia.hpp"

Amphibia::Amphibia()
{
    _unique = "не определим";
};

Amphibia::~Amphibia()
{
    //
};

const std::string Amphibia::getUnique()
{
    std::string buf;
    buf = "Цвет: " + _unique;
    return buf;
};


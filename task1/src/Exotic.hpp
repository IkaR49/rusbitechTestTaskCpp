#pragma once

#include <string>
#include "Animal.hpp"

class Exotic : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Exotic();
        Exotic(auto a) : Animal(a) {};
        virtual ~Exotic();
};


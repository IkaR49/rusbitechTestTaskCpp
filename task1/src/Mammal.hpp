#pragma once

#include <string>
#include "Animal.hpp"

class Mammal : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Mammal();
        Mammal(auto a) : Animal(a) {};
        virtual ~Mammal();
};


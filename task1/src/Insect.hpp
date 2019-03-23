#pragma once

#include <string>
#include "Animal.hpp"

class Insect : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Insect();
        Insect(auto a) : Animal(a) {};
        virtual ~Insect();
};


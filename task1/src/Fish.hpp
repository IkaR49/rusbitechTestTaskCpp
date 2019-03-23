#pragma once

#include <string>
#include "Animal.hpp"

class Fish : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Fish();
        Fish(auto a) : Animal(a) {};
        virtual ~Fish();
};


#pragma once

#include <string>
#include "Animal.hpp"

class Bird : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Bird();
        Bird(auto a) : Animal(a) {};
        virtual ~Bird();
};


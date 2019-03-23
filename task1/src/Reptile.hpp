#pragma once

#include <string>
#include "Animal.hpp"

class Reptile : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Reptile();
        Reptile(auto a) : Animal(a) {};
        virtual ~Reptile();
};


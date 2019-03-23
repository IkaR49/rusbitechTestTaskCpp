#pragma once

#include <string>
#include "Animal.hpp"

class Amphibia : public Animal
{
    private:
        //
    protected:
        virtual const std::string getUnique();
    public:
        Amphibia();
        Amphibia(auto a) : Animal(a) {};
        virtual ~Amphibia();
};


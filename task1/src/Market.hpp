#pragma once

#include <string>
#include <vector>
#include "Animal.hpp"

// Класс магазина

class Market
{
    private:
        std::vector <Animal*> _list;
    protected:
        bool exist(int);
    public:
        Market();
        ~Market();
        // Getters
        int getCount();
        Animal* getAnimal(int);
        // Setters
        int addAnimal(Animal*);
        float sellAnimal(int, float);
        bool delAnimal(int);
};


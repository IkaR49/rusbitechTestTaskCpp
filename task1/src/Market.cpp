#include <string>
#include <vector>
#include "Market.hpp"

#include "Animal.hpp"
#include "Amphibia.hpp"
#include "Bird.hpp"
#include "Exotic.hpp"
#include "Fish.hpp"
#include "Insect.hpp"
#include "Mammal.hpp"
#include "Reptile.hpp"

Market::Market()
{
    //
};
Market::~Market()
{
    // Обратный обход вектора по двум причинам:
    // 1. Лишь один раз вызывается vector.size()
    // 2. Удаление последнего элемента быстрее
    // Аргумент против такого подхода: оптимизатор может быть сработал бы лучше
    // Но это не точно
    for (int i = this->getCount() - 1; i >= 0; i--)
        this->delAnimal(i);
};

// Getters
int Market::getCount()
{
    return _list.size();
};

Animal* Market::getAnimal(int id)
{
    if (this->exist(id))
        return _list.at(id);
    return nullptr;
};

bool Market::exist(int id)
{
    return (id >= 0) && (id < this->getCount());
}

// Setters
int Market::addAnimal(Animal* baseAnimal)
{
    Animal* newAnimal;
    std::string species = baseAnimal->getSpecies();

    if (species == "Кот" || species == "Собака" || species == "Грызун")
        newAnimal = new Mammal(baseAnimal);
    else if (species == "Лягушка" || species == "Ящерица")
        newAnimal = new Amphibia(baseAnimal);
    else if (species == "Попугай" || species == "Канарейка")
        newAnimal = new Bird(baseAnimal);
    else if (species == "Пиранья" || species == "Гуппи")
        newAnimal = new Fish(baseAnimal);
    else if (species == "Паук" || species == "Бабочка")
        newAnimal = new Insect(baseAnimal);
    else if (species == "Змея" || species == "Черепаха")
        newAnimal = new Reptile(baseAnimal);
    else {
        newAnimal = new Exotic(baseAnimal);
        newAnimal->setUnique("Название вида: " + species, true);
        newAnimal->setSpecies("exotic");
    }

    // delete baseAnimal;
    // baseAnimal = newAnimal;

    _list.push_back(newAnimal);
    return this->getCount() - 1;
};

float Market::sellAnimal(int id, float money)
{
    float surplus;
    Animal* animal = this->getAnimal(id);
    if (animal == nullptr)
        throw 1;

    surplus = money - animal->getCost();
    if (surplus >= 0)
        if (!this->delAnimal(id))
            throw 2;
    return surplus;
};

bool Market::delAnimal(int id)
{
    if (!this->exist(id))
        return false;

    delete _list.at(id);
    _list.erase(_list.begin() + id);
    return true;
}


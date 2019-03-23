#include <string>
#include <time.h>
#include "Animal.hpp"
#include <iostream>

// Вспомогательная фнукция: возвращает максимально возможное количество
// дней в указанном месяце и указанном году. Если год опущен - он всегда
// считается невисокосным
// Месяцы нумеруются от 1 до 12
int maxDays(int month, int year = 1900)
{
    if (month < 0 || year < 0 || month > 12)
        return -1;

    int days = 0;
    if (month == 2) {
        if (!(year % 100))
            if (!(year % 400))
                days = 29;
            else
                days = 28;
        else if (!(year % 4))
            days = 28;
    } else if ((month < 8 && (month % 2)) ||
               (month > 7 && !(month % 2)))
        days = 31;
    else
        days = 30;

    return days;
}

Animal::Animal()
{
    _moniker = "";
    _species = "";
    _cost = 0;
    _unique = "";
    for (int i = 0; i < 3; i++)
        _birthDate[i] = 0;
}

Animal::Animal(Animal* baseAnimal)
{
    _moniker = baseAnimal->getMoniker();
    _species = baseAnimal->getSpecies();
    _cost = baseAnimal->getCost();
    _unique = baseAnimal->getRawUnique();
    for (int i = 0; i < 3; i++)
        _birthDate[i] = baseAnimal->getRawBirthDate(i);
}

Animal::~Animal()
{
    //
}

// Getters
const std::string Animal::getSpecies()
{
    return _species;
}

const std::string Animal::getMoniker()
{
    return _moniker;
}

const std::string Animal::getAge()
{
    struct tm *now;
    time_t tt = time(NULL);
    now = localtime(&tt);

    int fullDays = now->tm_mday - _birthDate[0];
    int fullMonths = now->tm_mon + 1 - _birthDate[1];
    int fullYears = (now->tm_year - _birthDate[2]) % 100;

    if (fullDays < 0) {
        if (now->tm_mon == 0) {
            fullDays += maxDays(12, now->tm_year - 1);
            fullYears -= 1;
        } else fullDays += maxDays(now->tm_mon, now->tm_year);
        fullMonths -= 1;
    }
    if (fullMonths < 0) {
        fullMonths += 12;
        fullYears -= 1;
    }

    std::string age = "";
    if (fullYears) age += std::to_string(fullYears) + " years ";
    if (fullYears < 4 && fullMonths)
        age += std::to_string(fullMonths) + " months ";
    if (fullYears == 0 && fullMonths < 4)
            age += std::to_string(fullDays) + " days";

    return age;
}

const float Animal::getCost()
{
    return _cost;
}

const std::string Animal::getRawUnique()
{
    return _unique;
}

const int Animal::getRawBirthDate(int i)
{
    return _birthDate[i];
}

const std::string Animal::getFullInfo()
{
    std::string result = "";
    result += "Вид: "; result += this->getSpecies(); result += "\n";
    result += "Кличка: "; result += this->getMoniker(); result += "\n";
    result += "Возраст: "; result += this->getAge(); result += "(";
        result += std::to_string(this->getRawBirthDate(0)); result += ".";
        result += std::to_string(this->getRawBirthDate(1)); result += ".";
        result += std::to_string(this->getRawBirthDate(2)); result += ")\n";
    result += this->getUnique(); result += "\n";
    result += "Цена: "; result += std::to_string(this->getCost());

    return result;
}

// Setters
void Animal::setSpecies(const std::string& species)
{
    _species = species.empty() ? "exotic" : species.c_str();
}

void Animal::setMoniker(const std::string& moniker)
{
    _moniker = moniker.empty() ? "none" : moniker.c_str();
}

void Animal::setBirthDate(int d, int m, int y)
{
    // Определим границы количества дней и месяцев
    if (d < 1) d = 1;
    if (m < 1) m = 1;
    else if (m > 12) m = 12;

    // Определим верхнюю границу количества дней
    if (d > maxDays(m, y)) d = maxDays(m, y);

    _birthDate[0] = d;
    _birthDate[1] = m;
    _birthDate[2] = y % 100; // Сохраним только последние две цифры года
}

void Animal::setCost(float cost)
{
    _cost = (cost > 0) ? cost : 0;
}

void Animal::setUnique(const std::string& unique, bool append)
{
    if (append)
        _unique += "\n" + unique;
    else
        _unique = unique;
};


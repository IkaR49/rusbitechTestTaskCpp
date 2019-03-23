#pragma once

#include <string>

// Общий класс описания животных

class Animal
{
    private:
        std::string _species;   // Вид животного
        std::string _moniker;   // Кличка
        int _birthDate[3];     // Дата рождения
        float _cost;            // Цена
    protected:
        std::string _unique;
        virtual const std::string getUnique() = 0;
    public:
        Animal();
        Animal(Animal*);
        virtual ~Animal();
        // Getters
        const std::string getSpecies();
        const std::string getMoniker();
        const std::string getAge();
        const float getCost();
        const std::string getRawUnique();
        const int getRawBirthDate(int);
        const std::string getFullInfo();
        // Setters
        void setSpecies(const std::string&);
        void setMoniker(const std::string&);
        void setBirthDate(int, int, int);
        void setCost(float);
        // Если второй параметр true - строка будет ДОБАВЛЕНА, иначе заменит
        // содержимое поля _unique
        void setUnique(const std::string&, bool = false);
};


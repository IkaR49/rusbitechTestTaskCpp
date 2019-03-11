#pragma once

#include <string>

// Общий класс описания животных

class Animal
{
	private:
		std::string _species;	// Вид животного
		std::string _moniker;	// Кличка
		/**/ _birthDate;	// Дата рождения
		unsigned float cost;	// Цена
	protected:
		//
	public:
		Animal();
		~Animal();
		// Getters
		std::string getSpecies();
		std::string getMoniker();
		unsigned int getAge();
		unsigned float getCost();
		// Setters
		void setSpecies(const std::string *)
		void setMoniker(const std::string *)
		void setBirthDate(/**/)
		void setCost(float)
};


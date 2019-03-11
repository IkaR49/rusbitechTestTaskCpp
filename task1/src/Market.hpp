#pragma once

#include <string>
#include "Animal.hpp"

// Класс магазина

class Market
{
	private:
		int _count;
	protected:
		//
	public:
		Market();
		~Market();
		
		// Getters
		int getCount();
		Animal* getAnimal(int); //?

		// Setters
		int addAnimal(std::string&);
		bool sellAnimal(int, double);
};

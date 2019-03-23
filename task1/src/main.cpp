#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Market.hpp"
#include "Animal.hpp"
#include "Exotic.hpp"

std::string COMMANDS[] = {
    "help",
    "add",
    "list",
    "info",
    "sell",
    "save",
    "load",
    "quit"
};
std::string COMMANDS_HELP[] = {
    "Отобразить список доступных команд",
    "Выставить животное на продажу",
    "Отобразить список всех животных, доступных к покупке",
    "Отобразить информацию о выбранном животном",
    "Оформить документы на продажу животного",
    "Сохранить базу магазина в каталог с программой",
    "Загрузить базу магазина из каталога с программой",
    "Выйти из программы"
};

bool isNumber(std::string& number)
{
    for (auto elem : number)
        if (!isdigit(elem))
            return false;
    return true;
}

void showHelp()
{
    std::cout << "Список доступных команд: " << std::endl;
    for (int i = 0; i < 8; i++)
        std::cout << i << ") " << std::left << std::setw(12) << COMMANDS[i]
                  << COMMANDS_HELP[i] << std::endl;
    std::cout << "Возможен ввод номера команды, полного или частичного наименования (0, 'h', 'he' и 'help' - выводят эту страницу помощи)." << std::endl;
}

void showHello()
{
    std::cout << "Animarket v0.0.0p0 (и никогда больше нуля)" << std::endl;
    showHelp();
}

void showAdd(Market& market)
{
    Animal* newAnimal = new Exotic;
    std::cout << "Введите информацию о животном. В квадратных скобках указаны стандартные значения. В круглых - образец заполнения" << std::endl;
    std::string buf;

    std::cout << "Вид [exotic]: ";
    std::getline(std::cin, buf);
    newAnimal->setSpecies(buf);

    std::cout << "Кличка: [none]: ";
    std::getline(std::cin, buf);
    newAnimal->setMoniker(buf);

    std::cout << "Дата рождения (dd.mm.yyyy): ";
    std::getline(std::cin, buf);
    int a = buf.find(".");
    int b = buf.rfind(".");
    newAnimal->setBirthDate(std::stoi(buf.substr(0, a)),
                         std::stoi(buf.substr(a+1, b-a-1)),
                         std::stoi(buf.substr(b+1)));

    std::cout << "Стоимость: ";
    std::getline(std::cin, buf);
    newAnimal->setCost(std::stof(buf));

    std::cout << "Особенности: ";
    std::getline(std::cin, buf);
    newAnimal->setUnique(buf);

    std::cout << newAnimal->getSpecies() << " " << newAnimal->getMoniker()
              << " получил номер " << market.addAnimal(newAnimal)
              << std::endl;
    delete newAnimal;
}

void showList(Market& market)
{
    if (market.getCount() == 0) {
        std::cout << "Данных о животных нет" << std::endl;
        return;
    }

    std::cout.setf(std::ios::left, std::ios::adjustfield);
    for (int i = 0; i < 70; i++) std::cout << "-";
    std::cout << std::endl;

    std::cout.width(3); std::cout << "#";
    std::cout.width(29); std::cout << (" | Вид");
    std::cout.width(29); std::cout << (" | Кличка");
    std::cout.width(5); std::cout << (" | Цена");
    std::cout << std::endl;

    for (int i = 0; i < 70; i++) std::cout << "-";
    std::cout << std::endl;

    for (int i = 0; i < market.getCount(); i++)
    {
        std::cout.width(3); std::cout << i;
        std::cout.width(29); std::cout << (" | " + market.getAnimal(i)->getSpecies());
        std::cout.width(29); std::cout << (" | " + market.getAnimal(i)->getMoniker());
        std::cout.width(5); std::cout << (" | " + std::to_string(market.getAnimal(i)->getCost()));
        std::cout.width(0); std::cout << std::endl;
    }
    for (int i = 0; i < 70; i++) std::cout << "-";
    std::cout << std::endl;
}

void showInfo(Market& market)
{
    std::cout << "Введите номер животного для получения подробной информации: ";
    std::string number;
    std::getline(std::cin, number);

    if (isNumber(number)) {
        Animal* animal = market.getAnimal(std::stoi(number));
        if (animal != nullptr) {
            std::cout << animal->getFullInfo() << std::endl;
            return;
        }
    }
    std::cout << "Нет такого животного" << std::endl;
}

void showSell(Market& market)
{
    std::cout << "Введите номер животного для продажи: ";
    std::string number;
    std::getline(std::cin, number);

    std::cout << "Введите полученную сумму от покупателя: ";
    float money;
    std::cin >> money;

    try {
        if (isNumber(number)) {
            float surplus = market.sellAnimal(std::stoi(number), money);
            std::cout << ((surplus < 0) ?
                            "Недостаточно средств: " :
                            "Продаша успешна. Ваша сдача: ")
                      << fabs(surplus) << std::endl;
        } else throw 1;
    } catch (int er) {
        std::cout << "Возникла ошибка Sell-" << er << " : ";
        switch (er) {
            case 1 : std::cout << "Нет животного c таким номером"; break;
            case 2 : std::cout << "Не получается удалить элемент вектора"; break;
            default: std::cout << "Ошибка не опознана";
        }
        std::cout << std::endl;
    }
}

void showSave(Market& market)
{
    try {
        if (market.getCount() < 1) throw 1;
        std::ofstream fout("animals.txt", std::ios_base::trunc);
        if (!fout.is_open()) throw 2;

        fout << std::to_string(market.getCount()) << std::endl;
        try {
            for (int i = 0; i < market.getCount(); i++) {
                Animal* animal = market.getAnimal(i);
                fout << animal->getSpecies() << std::endl
                     << animal->getMoniker() << std::endl
                     << std::to_string(animal->getCost()) << std::endl;
                for (int j = 0; j < 3; j++)
                    fout << std::to_string(animal->getRawBirthDate(j)) << ((j < 2) ? "." : "");
                //fout << std::endl;
                fout << animal->getRawUnique() << std::endl
                     << "NEXT" << std::endl;
            }
        } catch (...) { throw 3; }
        fout.close();
    } catch(int err) {
        std::cout << "Возникла ошибка Save-" << err << " : ";
        switch (err) {
            case 1 : std::cout << "Данных нет, сохранять нечего" << std::endl;
            case 2 : std::cout << "Не удаётся создать файл animals.txt"; break;
            default: std::cout << "Ошибка не распознана";
        }
        std::cout << std::endl;
    }
}

void showLoad(Market& market)
{
    try {
        std::ifstream fin("animals.txt", std::ios::in);
        if (!fin.is_open()) throw 1;

        Animal* newAnimal;
        try {
            std::string buf;
            std::getline(fin, buf);
            int num = std::stoi(buf);
            for (int i = 0; i < num; i++) {
                newAnimal = new Exotic;

                std::getline(fin, buf);
                newAnimal->setSpecies(buf);

                std::getline(fin, buf);
                newAnimal->setMoniker(buf);

                std::getline(fin, buf);
                newAnimal->setCost(std::stof(buf));

                std::getline(fin, buf);
                int a = buf.find(".");
                int b = buf.rfind(".");
                newAnimal->setBirthDate(std::stoi(buf.substr(0, a)),
                                        std::stoi(buf.substr(a+1, b-a-1)),
                                        std::stoi(buf.substr(b+1)));

                buf = "";
                newAnimal->setUnique(buf);
                std::getline(fin, buf);
                while (buf != "NEXT") {
                    newAnimal->setUnique(buf, true);
                    std::getline(fin, buf);
                }

                market.addAnimal(newAnimal);
                delete newAnimal;

            }
        } catch (...) {
            delete newAnimal;
            throw 2;
        }

        fin.close();
    } catch (int err) {
        std::cout << "Возникла ошибка Load-" << err << " : ";
        switch (err) {
            case 1 : std::cout << "Не удаётся открыть файл animal.txt"; break;
            case 2 : std::cout << "Неверная структура файла, чтение остановлено."; break;
            default: std::cout << "Ошибка не распознана.";
        }
        std::cout << std::endl;
    }
    showList(market);
}

int getCommand()
{
    std::cout << "> ";

    std::string input;
    std::getline(std::cin, input);

    if (!input.empty())
    {
        // Любую цифру можно вернуть сразу же: она легко обработается в switch-case
        if ((input.size() == 1) && isdigit(input[0]))
              return std::stoi(input);

        // Ищем соответствие хотя бы части первых символов команды
        for (int i = 0; i < 8; i++)
            if (COMMANDS[i].find(input) == 0)
                return i;
        return -2;
    }
    return -1;
}

int main ()
{
    Market market;

    showHello();
    do {
        try {
            switch(getCommand())
            {
                default : std::cout << "Неизвестная команда" << std::endl;
                case 0  : showHelp(); break;
                case 1  : showAdd(market); break;
                case 2  : showList(market); break;
                case 3  : showInfo(market); break;
                case 4  : showSell(market); break;
                case 5  : showSave(market); break;
                case 6  : showLoad(market); break;
                case 7  : return 0;
                case -1 : /* do nothing */;
            }
        } catch (...) {
            std::cout << "Возникла ошибка обработки данных" << std::endl;
        }
    } while (true);
}


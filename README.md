# Что это?

В этом репозитории расположено моё тестовое задание, которое я делал при трудоустройстве в свою первую it-компанию, а именно АО "НПО РусБИТех", департамент виртуальных тренажёров и трёхмерной визуализации.
Было это в 2019 году.

# Что почём

В папке с каждым заданием ещё так же находятся по README файлу, где расписано конкретно как это работает, и постановка
исходного задания.

По умолчанию выполнение корневого Makefile перестроит только задания 1 и 2, третье не будет изменено, чтобы не затереть pdf файл.
Для того, чтобы заново собрать 3 задание надо выполнить: *make math* или *make all* (последнее пересоберёт все 3 задания).

## Что необходимо для сборки

Я использовал:
* Для 1 задания:
* sed 4.2.2 (в Windows входит в состав пакета MSYS)
* Для 1 и 2 задания:
* * GNU Make 4.1 (в Windows - mingw32-make из пакета MinGW)
* * GCC 5.5.0 (в Windows - gcc из пакета MinGW)
* Для 2 задания:
* * QMake 2.01a
* * Qt 4.8.7
* Для 3 задания:
* * pdfeTeX 3.141592-1.21a-2.2
* * dvips(k) 5.95a
* * kpathsea 3.5.4
* * ps2pdf из пакета GhostScript

# Задание 1

Консольное приложение - магазин животных.

# Задание 2

Простейшее GUI приложение на Qt.

# Задание 3

Математические преобразования треугольника, описаны средствами LaTeX, конечный pdf файл приложен.

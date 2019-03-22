ifeq ($(OS),Windows_NT)
	MAKE ?= mingw32-make.exe
else
	MAKE ?= make
endif

.PHONY : progs math all task1 task2 task3 clean

progs : task1 task2
math : task3
all : progs math

task1 :
	$(MAKE) -C task1

task2 :
	$(MAKE) -C task2

task3 :
	$(MAKE) -C task3

clean:
	$(MAKE) -C task1 clean
	$(MAKE) -C task2 clean
	$(MAKE) -C task3 clean


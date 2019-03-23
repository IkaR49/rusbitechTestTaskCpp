ifeq ($(OS),Windows_NT)
	exec := bin/animarket.exe
	MAKE ?= mingw32-make.exe
else
	exec := bin/animarket
	MAKE ?= make
endif

compiler = g++ -c -Wall -std=c++14
linker = g++ -std=c++14
depmaker = g++ -MM

nothing =
sources = $(sort $(wildcard src/*.cpp))
objects = $(patsubst src/%.cpp, obj/%.o, $(sources))
depends = $(patsubst src/%.cpp, dep/%.d, $(sources))

subdirs = dep obj bin

.PHONY : all clean depend

# Если для какого-то файла *.cpp нет соответствующего *.d
ifeq ($(findstring $(strip $(depends)), $(sort $(wildcard dep/*.d))), $(nothing))

# Сначала строим все зависимости, создаём каталоги и снова запускаем этот Makefile
all : $(subdirs) depend
	@$(MAKE)

else

# Приступаем к компиляции
all : $(exec) ;
# Подключаем все построенные зависимости
include $(wildcard dep/*.d)

endif

clean:
	rm -rf $(subdirs)
depend : $(depends) ;
$(subdirs) :
	mkdir $@

# Создание списка зависимостей каждого файла с исходным кодом средствами компилятора
dep/%.d : src/%.cpp
	$(depmaker) $< | sed '1s|^|$@ obj/|' > $@

obj/%.o : dep/%.d
	$(compiler) $(filter %.cpp, $^) -o $@

$(exec) : $(objects)
	$(linker) $^ -o $@


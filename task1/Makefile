CC = g++
CFLAGS = -c -Wall
LDFLAGS =

obj/Animal.o: src/Animal.cpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Amphibia.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Bird.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Fish.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Insect.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Mammal.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Reptile.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/Market.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

obj/main.o: src/.cpp src/.hpp src/Animal.hpp obj
	$(CC) $(CFLAGS) -o obj/Animal.o src/Animal.cpp src/Animal.hpp

bin/animarket: bin obj/main.o obj/Market.o obj/Animal.o obj/Amphibia.o obj/Bird.o obj/Fish.o obj/Insect.o obj/Mammal.o obj/Reptile.o
	$(CC) $(CFLAGS) -o bin/animarket obj/main.o obj/Animal.o obj/Amphibia.o obj/Bird.o obj/Fish.o obj/Insect.o obj/Mammal.o obj/Reptile.o
obj:
	mkdir obj
bin:
	mkdir bin

clean:
	rm -rf bin
	rm -rf obj

OBJECTS := main.o arena.o character.o characterManager.o jsonParser.o player.o
COMPILERFLAGS := -std=c++17 -g -Wall -Werror -Wextra 
COMPILER := g++

CPPFILES := JSON.cpp Monster.cpp Hero.cpp Map.cpp Game.cpp main.cpp

build: $(OBJECTS)
	$(COMPILER) -o a.out $(OBJECTS)

main.o: main.cpp arena.cpp character.cpp characterManager.cpp jsonParser.cpp player.cpp
	$(COMPILER) -c main.cpp
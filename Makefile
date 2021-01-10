OBJECTS := main.o character.o player.o jsonParser.o mapReader.o map.o game.o enemy.o
COMPILERFLAGS := -std=c++17 -g -Wall -Werror -Wextra 
COMPILER := g++

CPPFILES := main.cpp character.cpp player.cpp jsonParser.cpp mapReader.cpp map.cpp game.cpp enemy.cpp

build: $(OBJECTS)
	$(COMPILER) $(COMPILERFLAGS) -o a.out $(OBJECTS)

main.o: main.cpp character.h player.h jsonParser.h mapReader.h map.h game.h enemy.h
	$(COMPILER) $(COMPILERFLAGS) -c main.cpp

in_out_tests:
	chmod +x check_units.sh && ./check_units.sh

unit_tests:
	cd tests && cmake . && make

run_unit_tests:
	cd tests && ./runUnitTests

static_code_analysis:
	cppcheck $(CPPFILES) --output-file=cppcheck_results.txt && chmod +x check_warning.sh && ./check_warning.sh && chmod +x check_error.sh && ./check_error.sh && ./valgrind_play_game.sh
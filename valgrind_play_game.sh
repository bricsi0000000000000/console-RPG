#!/bin/bash

valgrind --log-file="valgrind_output.txt" --leak-check=full ./a.out maps/map.csv units/unit1.json units/unit2.json < "valgrind_play_game_input.txt"

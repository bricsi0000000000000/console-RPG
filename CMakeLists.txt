cmake_minimum_required(VERSION 3.16)

project(RPG-game)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(rpg main.cpp arena.cpp character.cpp characterManager.cpp jsonParser.cpp player.cpp)
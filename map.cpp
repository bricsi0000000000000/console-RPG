#include <iostream>

#include "map.h"

Map::Map(const std::string& name, const two_d_vector& cells) : name(name), cells(cells) {}

Map::~Map() {}

int Map::GetCell(int row, int column){
  return cells[row][column];
}

void Map::Display(){
  for(int row_index = 0; row_index < cells.size(); row_index++){
    for(int column_index = 0; column_index <= cells[row_index].size(); column_index++){
      if(column_index == 0                       && row_index == 0 ||
         column_index == cells[row_index].size() && row_index == 0 ||
         column_index == 0                       && row_index == cells.size() ||
         column_index == cells[row_index].size() && row_index == cells.size())
      {
        std::cout << '+';
      }
      else if(column_index == 0 ||
              column_index == cells[row_index].size())
      {
        std::cout << '|';
      }
      else if(row_index == 0){
        std::cout << '-';
      }
      else{
        if(cells[row_index][column_index] == 0){ // empty
          std::cout << ' ';
        }
        else if(cells[row_index][column_index] == 1){ // wall
          std::cout << '#';
        }
        else if(cells[row_index][column_index] == 2){ // player
          std::cout << 'o';
        }
        else if(cells[row_index][column_index] == 3){ // enemy
          std::cout << 'M';
        }
      }
    }
    std::cout << '\n';
  }

  for(int column_index = 0; column_index <= cells[cells.size() - 1].size(); column_index++){
    if(column_index == 0 || column_index == cells[cells.size() - 1].size()){
      std::cout << '+';
    }
    else{
      std::cout << '-';
    }
  }
}

void Map::SetCell(int row_index, int column_index, int value){
  cells[row_index][column_index] = value;
}

std::string Map::GetName(){
  return this->name;
}

int Map::Move(int character_number, int row_index, int column_index){
  if(row_index <= 0 ||
     row_index >= cells.size() ||
     column_index <= 0 ||
     column_index >= cells[row_index].size())
  {
    return -1; // nothing
  }
  else{
    if(cells[row_index][column_index] == 1){
      return 1; // wall
    }
    else if(cells[row_index][column_index] == 3){
      return 3; // enemy
    }
    else if(GetCell(row_index, column_index) == 0){
      ClearValue(character_number);
      SetCell(row_index, column_index, character_number);
    }
  }

  return 0; // all good
}

void Map::ClearValue(int value){
  for(int row_index = 0; row_index < cells.size(); row_index++){
    for(int column_index = 0; column_index < cells[row_index].size(); column_index++){
      if(cells[row_index][column_index] == value){
        SetCell(row_index, column_index, 0);
      }
    }
  }
}
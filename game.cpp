#include <iostream>

#include "game.h"

Game::Game(std::string mapName, Map map, Character* character){
  this->map = map;
  this->character = character;
  Start();
  Update();
}

Game::~Game(){}

void Game::Start(){
  gameIsRunning = true;
}

void Game::Update(){
  while (gameIsRunning) {
    std::cout << "Directions: w,a,s,d\n";
    std::cout << "Step: ";
    std::string input;
    std::cin >> input;

    if(input == "w"){
      if(map.Move(character->GetNumber(), character->GetPositionRow() - 1, character->GetPositionColumn())){
        character->SetPositionRow(character->GetPositionRow() - 1);
        character->SetPositionColumn(character->GetPositionColumn());
      }
    }
    else if(input == "s"){
      if(map.Move(character->GetNumber(), character->GetPositionRow() + 1, character->GetPositionColumn())){
        character->SetPositionRow(character->GetPositionRow() + 1);
        character->SetPositionColumn(character->GetPositionColumn());
      }
    }
    else if(input == "a"){
      if(map.Move(character->GetNumber(), character->GetPositionRow(), character->GetPositionColumn() - 1)){
        character->SetPositionRow(character->GetPositionRow());
        character->SetPositionColumn(character->GetPositionColumn() - 1);
      }
    }
    else if(input == "d"){
      if(map.Move(character->GetNumber(), character->GetPositionRow(), character->GetPositionColumn() + 1)){
        character->SetPositionRow(character->GetPositionRow());
        character->SetPositionColumn(character->GetPositionColumn() + 1);
      }
    }
    else if(input == "e"){
      gameIsRunning = false;
      continue;
    }

    map.Display();

    std::cout << '\n';
  }
}

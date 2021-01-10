#include <iostream>

#include "game.h"

Game::Game(const Map& map, Player* player, const std::vector<Enemy>& enemies){
  this->map = map;
  this->player = player;
  this->enemies = enemies;
  Start();
  Update();
}

Game::~Game(){}

void Game::Start(){
  gameIsRunning = true;
}

void Game::Update(){
  while (gameIsRunning) {
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "\tStats\n";
    DisplayCharacter(player);
    std::cout << '\n';
    map.Display();
    std::cout << '\n';

    std::cout << "Directions: w,a,s,d\n";
    std::cout << "Step: ";
    std::string input;
    std::cin >> input;

    if(input == "w"){
      CheckMove(-1, 0);
    }
    else if(input == "s"){
      CheckMove(1, 0);
    }
    else if(input == "a"){
      CheckMove(0, -1);
    }
    else if(input == "d"){
      CheckMove(0, 1);
    }
    else if(input == "e"){
      std::cout << "\nExiting game..\n";
      gameIsRunning = false;
      continue;
    }
  }
}

void Game::CheckMove(int row_index, int column_index){
  int row = player->GetPositionRow() + row_index;
  int column = player->GetPositionColumn() + column_index;

  int move_result = map.Move(player->GetNumber(), row, column);
  if(move_result == 0){
    player->SetPositionRow(row);
    player->SetPositionColumn(column);
  }
  else if(move_result == -1){
    std::cout << "\tNothing there\n";
  }
  else if(move_result == 1){
    std::cout << "\tThere is a wall\n";
  }
  else if(move_result == 3){
    std::cout << "\t-------------There is a monster------------\n";
    Enemy enemy = GetEnemy(row, column);
    DisplayCharacter(&enemy);
    std::cout << "\tWould you like to attack the monster? (y/n) ";
    std::string input;
    std::cin >> input;
    if(input == "y"){
      Battle(player, &enemy);
    }
    else{

    }
  }
}

void Game::DisplayCharacter(Character* character){
  std::cout << "\t\tName: " << character->GetName() << '\n';
  std::cout << "\t\tHealth: " << character->GetHealth() << '\n';
  std::cout << "\t\tAttack damage: " << character->GetDamage() << '\n';
  std::cout << "\t\tAttack cooldown: " << character->GetAttackcooldown() << '\n';
  if(Player* player = dynamic_cast<Player*>(character)){
    std::cout << "\t\tLevel: " << player->GetLevel() << '\n';
    std::cout << "\t\tCurrent xp: " << player->GetXp() << '\n';
    std::cout << "\t\tNecessary xp to next level: " << (player->GetXp() - player->GetLevelXp() + LEVEL_UP_REQUIRED_XP)  << '\n';
  }
}

Enemy Game::GetEnemy(int row_index, int column_index){
  for(auto enemy : enemies){
    if(enemy.GetPositionRow() == row_index &&
       enemy.GetPositionColumn() == column_index)
    {
         return enemy;
    }
  }

  return Enemy();
}

void Game::Battle(Character* character1, Character* character2){
  int turnIndex = 0;

  int character1LastAttacked = turnIndex;
  int character2LastAttacked = turnIndex;

  while(character1->IsAlive() && character2->IsAlive()){
    if(character1->GetAttackcooldown() + character1LastAttacked <= turnIndex || turnIndex == 0){
      character1->Attack(character2);
      character1LastAttacked = turnIndex;
    }

    if(character2->IsAlive()){
      if(character2->GetAttackcooldown() + character2LastAttacked <= turnIndex || turnIndex == 0){
        character2->Attack(character1);
        character2LastAttacked = turnIndex;
      }
    }

    turnIndex++;
  }

  if(character1->IsAlive()){
    std::cout << "\tYou won\n";
    int row = character2->GetPositionRow();
    int column = character2->GetPositionColumn();
    map.SetCell(row, column, 0);
    player->SetPositionRow(row);
    player->SetPositionColumn(column);
    map.Move(character1->GetNumber(), row, column);
  }
  else {
    std::cout << "\tYou died\n";
    gameIsRunning = false;
  }
}
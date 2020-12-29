#include <iostream>

#include "arena.h"

Arena::Arena(){}
Arena::~Arena(){}

void Arena::Battle(Character* character1, Character* character2){
  int turnIndex = 0;

  int character1LastAttacked = turnIndex;
  int character2LastAttacked = turnIndex;

  while(character1->IsAlive() && character2->IsAlive()){
    if(character1->GetAttackcooldown() + character1LastAttacked <= turnIndex || turnIndex == 0){
      Duel(character1, character2);
      character1LastAttacked = turnIndex;
    }

    if(character2->IsAlive()){
      if(character2->GetAttackcooldown() + character2LastAttacked <= turnIndex || turnIndex == 0){
        Duel(character2, character1);
        character2LastAttacked = turnIndex;
      }
    }

    turnIndex++;
  }

  if(character1->IsAlive()){
    std::cout << character1->GetName() << " wins. Remaining HP: " << character1->GetHealth() << '\n';
  }
  else
  {
    std::cout << character2->GetName() << " wins. Remaining HP: " << character2->GetHealth() << '\n';
  }
}

void Arena::Duel(Character* character, Character* opponent){
  character->Attack(opponent);
}
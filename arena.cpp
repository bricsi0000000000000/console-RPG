#include <iostream>

#include "arena.h"

Arena::Arena(){}
Arena::~Arena(){}

void Arena::Battle(Character* character1, Character* character2){
  while(character1->IsAlive() && character2->IsAlive()){
    Duel(character1, character2);

    if(character2->IsAlive()){
      Duel(character2, character1);
    }
  }

  if(character1->IsAlive()){
    std::cout << character2->GetName() << " died. " << character1->GetName() << " wins.\n";
  }
  else
  {
    std::cout << character1->GetName() << " died. " << character2->GetName() << " wins.\n";
  }
}

void Arena::Duel(Character* character, Character* opponent){
  character->Attack(opponent);
}
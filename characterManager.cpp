#include <iostream>

#include "characterManager.h"

CharacterManager::CharacterManager(){}
CharacterManager::~CharacterManager(){
  for(auto character : characters){
    delete character;
  }
}

void CharacterManager::AddCharacter(Character* character){
  characters.push_back(character);
}

Character* CharacterManager::GetCharacter(std::string name){
  for(auto* character : characters){
    if(character->GetName().compare(name) == 0){
      return character;
    }
  }

  return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Character* character)
{
    os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage();
    return os;
}
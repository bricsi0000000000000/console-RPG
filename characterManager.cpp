#include "characterManager.h"
#include "player.h"

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

Character* CharacterManager::GetCharacter(int index){
  return characters[index];
}

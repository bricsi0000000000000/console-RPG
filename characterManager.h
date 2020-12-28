#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <vector>

#include "character.h"

class CharacterManager
{
private:
  std::vector<Character*> characters;
public:
  CharacterManager();
  ~CharacterManager();
  void AddCharacter(Character* character);
  Character* GetCharacter(std::string name);
};


#endif //CHARACTER_MANAGER_H

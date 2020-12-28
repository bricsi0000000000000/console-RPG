#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <vector>

#include "character.h"

class CharacterManager
{
private:
  std::vector<Character*> characters;
public:
  static Character* parseUnit(std::string fileName);
  CharacterManager();
  ~CharacterManager();
  void AddCharacter(Character* character);
  Character* GetCharacter(std::string name);
  Character* GetCharacter(int index);
};


#endif //CHARACTER_MANAGER_H

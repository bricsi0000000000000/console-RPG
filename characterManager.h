#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <vector>

#include "character.h"
#include "player.h"

/**
 * @class CharacterManager
 * @brief Manages characters.
*/
class CharacterManager
{
private:
  /**
   * Vector if characters.
  */
  std::vector<Character*> characters;
public:
  /**
   * Constructor for CharacterManager
  */
  CharacterManager();

  /**
   * Destructor for CharacterManager
  */
  ~CharacterManager();

  /**
   * Parses a unit from a json file.
   * @exception Throws runtime_error exception when the file not found.
  */
  static Player* parseUnit(std::string fileName);

  /**
   * Add a character to the characters vector.
  */
  void AddCharacter(Character* character);

  /**
   * @return A character by the name.
  */
  Character* GetCharacter(std::string name);

  /**
   * @return A character by index.
  */
  Character* GetCharacter(int index);
};


#endif //CHARACTER_MANAGER_H

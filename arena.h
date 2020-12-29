#ifndef ARENA_H
#define ARENA_H

#include "character.h"

/**
 * @class Arena
 * @brief Represents an arena, where characters can fight each other.
*/
class Arena
{
private:
public:
  /**
   * Constructor for Arena
  */
  Arena();

  /**
   * Destructor for Arena
  */
  ~Arena();

  /**
   * Handles a battle between two characters while one of them dies.
   * @param character1 The first character.
   * @param character2 The second character.
  */
  void Battle(Character* character1, Character* character2);

  /**
   * Handles a duel between two characters for only one hit.
   * @param character Character who attacks.
   * @param opponent Character who is attacked.
  */
  void Duel(Character* character, Character* opponent);
};

#endif //ARENA_H

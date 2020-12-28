#ifndef ARENA_H
#define ARENA_H

#include "character.h"

class Arena
{
private:
public:
  Arena();
  ~Arena();
  void Battle(Character* character1, Character* character2);
  void Duel(Character* character, Character* opponent);
};

#endif //ARENA_H

#ifndef PLAYER_H
#define PLAYER_H

#define LEVEL_UP_REQUIRED_XP 100
#define LEVEL_UP_GAIN_MAX_HEALTH_PERCENT 0.1
#define LEVEL_UP_GAIN_DAMAGE_PERCENT 0.1

#include <string>

#include "character.h"

class Player : public Character
{
private:
  void GainXp(unsigned int amount);
  void LevelUp(int lastXp, int newXp);
public:
  Player(std::string name,
         unsigned int health,
         float damage,
         float attackcooldown);
  ~Player();

  void Attack(Character* opponent);
};

#endif //PLAYER_H
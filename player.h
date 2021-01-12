#ifndef PLAYER_H
#define PLAYER_H

#define LEVEL_UP_REQUIRED_XP 100
#define LEVEL_UP_GAIN_MAX_HEALTH_PERCENT 0.1
#define LEVEL_UP_GAIN_DAMAGE_PERCENT 0.1

#include <string>

#include "character.h"

/**
 * @class Player
 * @brief Represents a player that is derived from Character.
*/
class Player : public Character
{
private:
  /**
   * Gains amount experience point.
   * @param amount How many experience point shuold be gained.
  */
  void GainXp(unsigned int amount);

  /**
   * Checks if the experience points are enough to step on the next level.
   * Default level up is 100 xp.
   * When level up happens the maximum health and damage grow by 10%.
  */
  void LevelUp();

  /**
   * Experience points that the character has.
  */
  unsigned int xp;

  /**
   * Experience points at level.
  */
  unsigned int levelXp;

  /**
   * Players actual level.
  */
  int level;

public:
  /**
   * Constructor for Player
   * @param name Name of the player.
   * @param health Health of the player.
   * @param damage Damage of the player.
   * @param attackcooldown Attack cooldown of the player.
  */
  Player(const std::string& name,
         unsigned int health,
         float damage,
         float attackcooldown,
         int position_row,
         int position_column,
         int number);

  /**
   * Constructor for character.
   * @param character Is a character from you want to build the player.
  */
  explicit Player(Character* character);

  /**
   * Destructor for Player.
  */
  ~Player();

  /**
   * Attacks an other character.
   * Overrides the Characters Attack method by adding gain xp.
  */
  void Attack(Character* opponent) override;

  /**
   * @return How many xp the character has.
  */
  int GetXp() const;

  /**
   * @return How many xp had the player at the current level.
  */
  int GetLevelXp() const;

  /**
   * @return Level of the player.
  */
  int GetLevel();
};

#endif //PLAYER_H
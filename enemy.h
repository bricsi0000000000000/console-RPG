#ifndef ENEMY_H
#define ENEMY_H

#include <string>

#include "character.h"

/**
 * @class Enemy
 * @brief Represents an enemy that is derived from Character.
*/
class Enemy : public Character
{
private:

public:
  /**
   * Constructor for Enemy
   * @param name Name of the player.
   * @param health Health of the player.
   * @param damage Damage of the player.
   * @param attackcooldown Attack cooldown of the player.
  */
  Enemy(std::string name,
         unsigned int health,
         float damage,
         float attackcooldown,
         int position_row,
         int position_column,
         int number);

  /**
   * Constructor for enemy.
   * @param character Is a character from you want to build the enemy.
  */
  explicit Enemy(Character* character);

  /**
   * Empty constructor.
  */
  Enemy();

  /**
   * Destructor for Enemy.
  */
  ~Enemy();

  /**
   * Attacks an other character.
   * Overrides the Characters Attack method by adding gain xp.
  */
  void Attack(Character* opponent) override;
};

#endif //ENEMY_H
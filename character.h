#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

/**
 * \class Character
 * \brief Represents a character.
 *        A Character can attack an other character.
*/
class Character
{
private:
  /**
   * Name of the character.
  */
  std::string name;

  /**
   * Attack cooldown of the character.
   * It shows that the character can attack after this many *seconds*.
  */
  float attackcooldown;

protected:
  /**
   * Maximum health of the character.
  */
  unsigned int maxHealth;
  
  /**
   * Current health of the character.
  */
  unsigned int currentHealth;

  /**
   * Damage of the character.
   * That many can deal this character to an other character.
  */
  float damage;

  /**
   * Experience points that the character has.
  */
  unsigned int xp;
public:
  /**
   * An other character attacks this charater.
   * @param opponent The other character that attacks this one.
   * @return How much damage the character suffered.
  */
  unsigned int GetAttacked(Character* opponent);

  /**
   * Constructor for character.
   * @param name Name of the character.
   * @param health Health of the character.
   * @param damage Damage of the character.
   * @param attackcooldown Attack cooldown of the character.
  */
  Character(const std::string& name,
            unsigned int health,
            float damage,
            float attackcooldown);

  /**
   * Destructor for character.
  */
  virtual ~Character();

  /**
   * @return The name of the character.
  */
  std::string GetName() const;

  /**
   * @return The health of the character.
  */
  unsigned int GetHealth() const;

  /**
   * @return The damage of the character.
  */
  float GetDamage() const;

  /**
   * @return The attack cooldown of the character.
  */
  float GetAttackcooldown() const;

  /**
   * Attacks an other character.
   * @param opponent The other character to attack.
  */
  virtual void Attack(Character* opponent);

  /**
   * @return That the character is alive or not.
  */
  bool IsAlive();

  /**
   * @return How many xp the character has.
  */
  int GetXp() const;

  /**
   * Operator overload to write the characters details nicely.
   * @param os Is the stream where to write.
   * @param character The character to write.
  */
  friend std::ostream& operator<<(std::ostream& os, const Character* character);
};

#endif //CHARACTER_H
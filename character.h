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

  int position_row;
  int position_column;
  int number;

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
   * @param number The number that represents this character. 2 is player and up from 3 are enemies.
  */
  Character(const std::string& name,
            const unsigned int health,
            float damage,
            float attackcooldown,
            int position_row,
            int position_column,
            int number);

  explicit Character(Character* character);
  Character();

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


  int GetPositionRow();
  int GetPositionColumn();
  int GetNumber();
  void SetNumber(int number);
  void SetPositionRow(int number);
  void SetPositionColumn(int number);
};

#endif //CHARACTER_H
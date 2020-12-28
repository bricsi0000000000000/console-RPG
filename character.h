#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
  std::string name;
  unsigned int health;
  float damage;

  void GetAttacked(Character* opponent);
public:
  Character(char* name,
            unsigned int health,
            float damage);
  ~Character();

  std::string GetName() const;
  unsigned int GetHealth() const;
  float GetDamage() const;
  void Attack(Character* opponent);
  friend std::ostream& operator<<(std::ostream& os, const Character* character);
  bool IsAlive();
};

#endif //CHARACTER_H
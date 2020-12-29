#include <iostream>

#include "character.h"

Character::Character(const std::string& name,
                     unsigned int health,
                     float damage,
                     float attackcooldown) : name(name)
{
  this->maxHealth = health;
  this->damage = damage;
  this->attackcooldown = attackcooldown;

  this->xp = 0;
  this->currentHealth = this->maxHealth;
}

Character::~Character(){}

std::string Character::GetName() const{
  return this->name;
}

unsigned int Character::GetHealth() const{
  return this->currentHealth;
}

float Character::GetDamage() const{
  return this->damage;
}

float Character::GetAttackcooldown() const{
  return this->attackcooldown;
}

void Character::Attack(Character* opponent){
  opponent->GetAttacked(this);
}

unsigned int Character::GetAttacked(Character* opponent){
  if(GetHealth() - opponent->GetDamage() >= 0){
    this->currentHealth -= opponent->GetDamage();
    return opponent->GetDamage();
  }
  else{
    int lastCurrentHealth = GetHealth();
    this->currentHealth = 0;
    return lastCurrentHealth;
  }
}

bool Character::IsAlive(){
  return GetHealth() > 0;
}

int Character::GetXp() const{
  return this->xp;
}

std::ostream& operator<<(std::ostream& os, const Character* character)
{
  os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage();
  return os;
}
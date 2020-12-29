#include <iostream>

#include "character.h"

Character::Character(std::string name,
                     unsigned int health,
                     float damage,
                     float attackcooldown)
{
  this->name = name;
  this->health = health;
  this->damage = damage;
  this->attackcooldown = attackcooldown;
}

Character::~Character(){}

std::string Character::GetName() const{
  return this->name;
}

unsigned int Character::GetHealth() const{
  return this->health;
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

void Character::GetAttacked(Character* opponent){
  if(this->health - opponent->GetDamage() >= 0){
    this->health -= opponent->GetDamage();
  }
  else{
    this->health = 0;
  }
}

bool Character::IsAlive(){
  return GetHealth() > 0;
}

std::ostream& operator<<(std::ostream& os, const Character* character)
{
    os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage();
    return os;
}
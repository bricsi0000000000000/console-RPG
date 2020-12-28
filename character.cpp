#include <iostream>

#include "character.h"

Character::Character(std::string name,
                     unsigned int health,
                     float damage)
{
  this->name = name;
  this->health = health;
  this->damage = damage;
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
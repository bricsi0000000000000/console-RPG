#include <iostream>

#include "character.h"

Character::Character(const std::string& name,
                     unsigned int health,
                     float damage,
                     float attackcooldown,
                     int position_row,
                     int position_column) : name(name)
{
  this->maxHealth = health;
  this->damage = damage;
  this->attackcooldown = attackcooldown;
  this->position_row = position_row;
  this->position_column = position_column;

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

int Character::GetPositionRow(){
  return position_row;
}
int Character::GetPositionColumn(){
  return position_column;
}

int Character::GetNumber(){
  return number;
}

void Character::SetNumber(int number){
  this->number = number;
}

void Character::SetPositionRow(int value){
  this->position_row = value;
}
void Character::SetPositionColumn(int value){
  this->position_column = value;
}

std::ostream& operator<<(std::ostream& os, const Character* character) {
  os << character->GetName() << ": HP: " << character->GetHealth() << ", DMG: " << character->GetDamage();
  return os;
}
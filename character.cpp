#include <iostream>

#include "character.h"

Character::Character(const std::string& name,
                     const unsigned int health,
                     float damage,
                     float attackcooldown,
                     int position_row,
                     int position_column,
                     int number) : name(name)
{
  this->maxHealth = health;
  this->damage = damage;
  this->attackcooldown = attackcooldown;
  this->position_row = position_row;
  this->position_column = position_column;
  this->number = number;

  this->currentHealth = this->maxHealth;
}

Character::Character(Character* character){
  this->name = character->GetName();
  this->maxHealth = character->GetHealth();
  this->damage = character->GetDamage();
  this->attackcooldown = character->GetAttackcooldown();
  this->position_row = character->GetPositionRow();
  this->position_column = character->GetPositionColumn();
  this->number = character->GetNumber();

  this->currentHealth = this->maxHealth;
}

Character::Character(){}

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

int Character::GetPositionRow(){
  return position_row;
}
int Character::GetPositionColumn(){
  return position_column;
}

int Character::GetNumber(){
  return number;
}

void Character::SetPositionRow(int value){
  this->position_row = value;
}
void Character::SetPositionColumn(int value){
  this->position_column = value;
}

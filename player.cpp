#include <iostream>

#include "player.h"
#include "character.h"

Player::Player(const std::string& name,
               unsigned int health,
               float damage,
               float attackcooldown,
               int position_row,
               int position_column,
               int number) : Character(name, health, damage, attackcooldown, position_row, position_column, number)
               {
                  level = 1;
                  xp = 0;
                  levelXp = 0;
               }

Player::Player(Character* character) : Character(character)
              {
                level = 1;
                xp = 0;
                levelXp = 0;
              }

Player::~Player(){}

int Player::GetXp() const{
  return this->xp;
}

int Player::GetLevelXp() const{
  return levelXp;
}

void Player::GainXp(unsigned int amount){
  this->xp += amount;
  LevelUp();
}

void Player::Attack(Character* opponent){
  GainXp(opponent->GetAttacked(this));
}

void Player::LevelUp(){
  if(xp - levelXp > LEVEL_UP_REQUIRED_XP){
    this->maxHealth += this->maxHealth * LEVEL_UP_GAIN_MAX_HEALTH_PERCENT;
    this->damage += this->damage * LEVEL_UP_GAIN_DAMAGE_PERCENT;
    this->currentHealth = this->maxHealth;
    level++;
    levelXp = xp;
  }
}

int Player::GetLevel(){
  return level;
}
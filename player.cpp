#include <iostream>

#include "player.h"
#include "character.h"

Player::Player(std::string& name,
               unsigned int health,
               float damage,
               float attackcooldown) : Character(name, health, damage, attackcooldown){}

Player::~Player(){}

void Player::GainXp(unsigned int amount){
  int newXp = GetXp() + amount;
  LevelUp(GetXp(), newXp);
  this->xp = newXp;
}

void Player::Attack(Character* opponent){
  GainXp(opponent->GetAttacked(this));
}

void Player::LevelUp(int lastXp, int newXp){
  if(newXp / LEVEL_UP_REQUIRED_XP < lastXp / LEVEL_UP_REQUIRED_XP){
    this->maxHealth += this->maxHealth * LEVEL_UP_GAIN_MAX_HEALTH_PERCENT;
    this->damage += this->damage * LEVEL_UP_GAIN_DAMAGE_PERCENT;
    this->currentHealth = this->maxHealth;
  }
}
#include <iostream>

#include "enemy.h"
#include "character.h"

Enemy::Enemy(const std::string& name,
             unsigned int health,
             float damage,
             float attackcooldown,
             int position_row,
             int position_column,
             int number) : Character(name, health, damage, attackcooldown, position_row, position_column, number){}

Enemy::Enemy(Character* character) : Character(character){}

Enemy::Enemy() : Character(){}

Enemy::~Enemy(){}

void Enemy::Attack(Character* opponent){
  opponent->GetAttacked(this);
}

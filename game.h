#ifndef GAME_H
#define GAME_H

#include <string>

#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"

class Game
{
private:
  bool gameIsRunning;
  Map map;
  Player* player;
  std::vector<Enemy> enemies;
  void Start();
  void Update();
  void CheckMove(int row, int column);
  Enemy GetEnemy(int row_index, int column_index);
  void DisplayCharacter(Character* character);
  void Battle(Character* character1, Character* character2);
public:
  Game(const Map& map, Player* player, const std::vector<Enemy>& enemies);
  ~Game();
};



#endif //GAME_H
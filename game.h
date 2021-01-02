#ifndef GAME_H
#define GAME_H

#include <string>

#include "map.h"
#include "character.h"

class Game
{
private:
  bool gameIsRunning;
  Map map;
  Character* character;
  void Start();
  void Update();
public:
  Game(std::string mapName, Map map, Character* character);
  ~Game();
};



#endif //GAME_H
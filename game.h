#ifndef GAME_H
#define GAME_H

#include <string>

#include "map.h"
#include "character.h"
#include "player.h"
#include "enemy.h"

/**
 * @class Game
 * @brief Represents the logic of the game.
*/
class Game
{
private:
  /**
   * State of the game.
   * If true, the game is running.
   * If false, the game is over.
  */
  bool gameIsRunning;

  /**
   * Map where the game will be played.
  */
  Map map;

  /**
   * Player with whom the user will play.
  */
  Player* player;

  /**
   * Enemies on the map.
  */
  std::vector<Enemy> enemies;

  /**
   * Starts the game.
  */
  void Start();

  /**
   * Runs the games logic.
  */
  void Update();

  /**
   * Checks if the move is valid and decides what will happen next.
   * @param row How many cells step in tha players row.
   * @param column How many cells step in tha players column.
  */
  void CheckMove(int row, int column);

  /**
   * @return An enemy from enemies.
   * @param row_index Row index of the findable enemy.
   * @param column_index Column index of the findable enemy.
  */
  Enemy GetEnemy(int row_index, int column_index);

  /**
   * Displays informations from the character.
  */
  void DisplayCharacter(Character* character);

  /**
   * Duels two characters until one of them dies.
  */
  void Battle(Character* character1, Character* character2);
public:
  /**
   * Constructor for game.
   * @param map The map where the game will be played.
   * @param player The player with whom the user will play.
   * @param enemies Enemies on the map.
  */
  Game(const Map& map, Player* player, const std::vector<Enemy>& enemies);

  /**
   * Destructor for game.
  */
  ~Game();
};



#endif //GAME_H
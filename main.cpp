#include <iostream>
#include <memory>

#include "player.h"
#include "player.h"
#include "enemy.h"
#include "jsonParser.h"
#include "mapReader.h"
#include "map.h"
#include "game.h"

/**
 * @file
 * @brief Main function that calls when the program starts.
 * @param argc is the number of arguments
 * @param argv is an array that contains the arguments. First one is the programs name.
 */
int main(int argc, char *argv[]){
  JsonParser parser;

  if(argc < 4){
    std::cerr << "Nincs megadva eleg parameter. Meg kell adnod egy player-t, egy enemyt és egy map-et.\n";
    return 0;
  }
  else {
    try {
      MapReader mapReader;
      Map map = mapReader.ReadMap(argv[1]);

      Character* player_character = parser.parseUnitFromFile(argv[2]);
      Player player(player_character);
      delete player_character;

      Character* enemy_character = parser.parseUnitFromFile(argv[3]);
      Enemy enemy(enemy_character);
      delete enemy_character;

      map.SetCell(player.GetPositionRow(),
                  player.GetPositionColumn(),
                  player.GetNumber());

      map.SetCell(enemy.GetPositionRow(),
                  enemy.GetPositionColumn(),
                  enemy.GetNumber());

      std::vector<Enemy> enemies;
      enemies.push_back(enemy);

      Game game(map, &player, enemies);
    }
    catch(const std::exception& e){
      std::cerr << e.what() << '\n';
      return 0;
    }
  }
  
  return 0;
}

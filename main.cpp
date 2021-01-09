#include <iostream>
#include <memory>

#include "character.h"
#include "player.h"
#include "characterManager.h"
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

  CharacterManager characterManager;
  JsonParser parser;
  int characterNumbers = 2;

  if(argc < 3){
    std::cerr << "Nincs megadva eleg parameter. Meg kell adnod egy unit-ot és egy map-et.\n";
    return 0;
  }
  else {
    try {
      Character* character = parser.parseUnitFromFile(argv[1]);
      character->SetNumber(characterNumbers++);
      characterManager.AddCharacter(character);

      MapReader mapReader;
      Map map = mapReader.ReadMap(argv[2]);
      map.SetCell(character->GetPositionRow(),
                  character->GetPositionColumn(),
                  character->GetNumber());

      Game game(argv[2], map, character);
    }
    catch(const std::exception& e){
      std::cerr << e.what() << '\n';
      return 0;
    }
  }
  
  return 0;
}


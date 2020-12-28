#include <iostream>

#include "character.h"
#include "characterManager.h"
#include "arena.h"

int main(int argc, char *argv[]){

  CharacterManager characterManager;
  Arena arena;
    
  if(argc < 3){
    std::cerr << "Nincs megadva eleg parameter\n";
    return 0;
  }
  else {
    try
    {
      characterManager.AddCharacter(characterManager.parseUnit(argv[1]));
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return 0;
    }
    
    try
    {
      characterManager.AddCharacter(characterManager.parseUnit(argv[2]));
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return 0;
    }

    arena.Battle(characterManager.GetCharacter(0), characterManager.GetCharacter(1));
  }
  
  return 0;
}

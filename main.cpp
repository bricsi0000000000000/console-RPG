#include <iostream>

#include "character.cpp"
#include "characterManager.cpp"
#include "arena.cpp"

int main(int argc, char *argv[]){

  CharacterManager characterManager;
  Arena arena;
  
  if(argc < 7){
    std::cerr << "Nincs megadva eleg parameter\n";
    return 0;
  }
  else {
    characterManager.AddCharacter(new Character(argv[1], std::stoi(argv[2]), std::stoi(argv[3])));
    characterManager.AddCharacter(new Character(argv[4], std::stoi(argv[5]), std::stoi(argv[6])));

    arena.Battle(characterManager.GetCharacter(argv[1]), characterManager.GetCharacter(argv[4]));
  }
  
  return 0;
}
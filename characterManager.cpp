#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

#include "characterManager.h"
#include "player.h"

CharacterManager::CharacterManager(){}
CharacterManager::~CharacterManager(){
  for(auto character : characters){
    delete character;
  }
}

Player* CharacterManager::parseUnit(std::string fileName){
  std::fstream fileStream;
  fileStream.open(fileName, std::ios::in);
  if(fileStream){
    std::string content((std::istreambuf_iterator<char>(fileStream)),
                        (std::istreambuf_iterator<char>()));

    content.erase(std::remove(content.begin(), content.end(), ' '), content.end());
    content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());

    std::map<std::string, std::string> results;

    std::string key;
    std::string value;

    bool isKey = false;
    bool isValue = false;

    for (unsigned int i = 0; i < content.size(); i++)
    {
      if(content[i] == ','){
        isKey = false;
        isValue = false;
        results.insert({key, value});
        key = "";
        value = "";
      }

      if(content[i] == ':'){
        isValue = true;
        if(content[i + 1] == '"'){
          i++;
        }
        continue;
      }

      if(content[i] == '"'){
        if (isKey){
          isKey = false;
        }
        else{
          isKey = true;
          isValue = false;
        
          continue;
        }
      }

      if(isKey){
        key += content[i];
      }

       if(isValue){
        value += content[i];
      }
    }

    results.insert({key, value.substr(0, value.size() - 1)});

    return new Player(results.find("name")->second,
                      std::stoi(results.find("hp")->second),
                      std::stof(results.find("dmg")->second),
                      std::stof(results.find("attackcooldown")->second));
  }
  else
  {
    throw std::runtime_error("File doesn't exists!");
  }

  return nullptr;
}

void CharacterManager::AddCharacter(Character* character){
  characters.push_back(character);
}

Character* CharacterManager::GetCharacter(std::string name){
  for(auto* character : characters){
    if(character->GetName().compare(name) == 0){
      return character;
    }
  }

  return nullptr;
}

Character* CharacterManager::GetCharacter(int index){
  return characters[index];
}

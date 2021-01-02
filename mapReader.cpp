#include <sstream>
#include <iterator>
#include <vector>

#include "mapReader.h"

MapReader::MapReader(){}

MapReader::~MapReader(){}

Map MapReader::ReadMap(std::string fileName){
  std::string name;
  two_d_vector cells;

  std::fstream fileStream;
  fileStream.open(fileName, std::ios::in);

  if(fileStream){
    if (fileStream.is_open()) {
      int index = 0;
      std::string row;
      while(getline(fileStream, row)) {
        if(index++ == 0){
          name = row;
        }
        else{
          std::vector<int> cell_row;
          for(auto cell : row){
            if(cell != ';' && (cell - '0') != -35) {
              cell_row.push_back(cell - '0');
            }
          }

          cells.push_back(cell_row);
        }
      }
      fileStream.close();
   }
  }
  else{
    throw std::runtime_error("File doesn't exists!");
  }

  return Map(name, cells);
}
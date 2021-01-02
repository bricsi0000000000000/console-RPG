#ifndef MAP_READER_H
#define MAP_READER_H

#include <string>
#include <iostream>
#include <fstream>

#include "map.h"

class MapReader
{
private:
public:
  MapReader();
  ~MapReader();
  Map ReadMap(std::string fileName);
};


#endif //MAP_READER_H
#ifndef MAP_READER_H
#define MAP_READER_H

#include <string>
#include <iostream>
#include <fstream>

#include "map.h"

/**
 * @class MapReader
 * @brief Reads a map
*/
class MapReader
{
public:
  /**
   * Constructor for MapReader
  */
  MapReader();

  /**
   * Destructor for MapReader
  */
  ~MapReader();

  /**
   * Read a map from file.
   * @param fileName Name of the maps file.
  */
  Map ReadMap(std::string fileName);
};


#endif //MAP_READER_H
#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <string>

#include "character.h"

/**
 * @class JsonParser
 * @brief Parses a Character from a file, string or a file stream
*/
class JsonParser
{
private:
public:
  /**
   * Constructor for JsonParser
  */
  JsonParser();

  /**
   * Destructor for JsonParser
  */
  ~JsonParser();
  
  /**
   * Parses a unit from a string.
  */
  static Character* parseUnitFromFileContent(std::string content);

  /**
   * Parses a unit from file.
  */
  static Character* parseUnitFromFile(std::string fileName);

  /**
   * Parses a unit from a file stream.
   * @exception Throws runtime_error exception when the file not found.
  */
  static Character* parseUnitFromStream(std::fstream& fileStream);
};


#endif //JSON_PARSER_H
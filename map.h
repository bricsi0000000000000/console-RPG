#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

/**
 * @brief type definition for a two dimensional int vector.
*/
typedef std::vector<std::vector<int>> two_d_vector;

/**
 * @class Map
 * @brief Represents a map where the game will be played on.
*/
class Map
{
private:
  /**
   * Maps name.
  */
  std::string name;

  /**
   * Cells on the map.
  */
  two_d_vector cells;

  /**
   * Clears a cells value.
  */
  void ClearValue(int value);
public:
  /**
   * Constructor for map.
   * @param name Name if the map. Default is an empy string.
   * @param cells Cells of the map. Default is an empty two dimensional vector.
  */
  Map(const std::string& name = "", const two_d_vector& cells = {});

  /**
   * Destructor for map.
  */
  ~Map();

  /**
   * Sets a cells value on the specific coordinate.
  */
  void SetCell(int row_index, int column_index, int value);

  /**
   * Returns a cells value on the specific coordinate.
  */
  int GetCell(int row, int column);

  /**
   * Displays the map.
  */
  void Display();

  /**
   * @return The name of the map.
  */
  std::string GetName();

  /**
   * Moves a character to the specific coordinate.
   * @param character_number The characters number you want to move.
   * @param row_index The row index where you want to move the character.
   * @param column_index The column index where you want to move the character.
  */
  int Move(int character_number, int row_index, int column_index);
};

#endif //MAP_H
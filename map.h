#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

typedef std::vector<std::vector<int>> two_d_vector;

class Map
{
private:
  std::string name;
  two_d_vector cells;
  void ClearValue(int value);
public:
  Map(const std::string& name = "", const two_d_vector& cells = {});
  ~Map();
  void SetCell(int row_index, int column_index, int value);
  int GetCell(int row, int column);
  void Display();
  std::string GetName();
  int Move(int character_number, int row_index, int column_index);
};

#endif //MAP_H
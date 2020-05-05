#include <vector>

using namespace std;

class Solution {
public:
  enum Direction {
    Left,
    Down,
    Right,
    Up
  };

  struct Coords {
    int row;
    int col;
  };

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    Direction dir = Direction::Right;
    Coords coords = { 0, 0 };
    vector<vector<int>> mapOfMatrix;
    int numOfRows = matrix.size();
    if (numOfRows == 0)
      return result;
    int numOfCols = matrix[0].size();
    if (numOfCols == 0)
      return result;
    mapOfMatrix.resize(numOfRows);
    for (int i = 0; i < numOfRows; ++i)
      mapOfMatrix[i].resize(numOfCols);
    for (;;) {
      result.push_back(matrix[coords.row][coords.col]);
      mapOfMatrix[coords.row][coords.col] = 1;
      switch (dir) {
      case Right:
        if (coords.col + 1 < numOfCols && mapOfMatrix[coords.row][coords.col + 1] == 0)
          coords.col += 1;
        else if (coords.row + 1 < numOfRows && mapOfMatrix[coords.row + 1][coords.col] == 0) {
          dir = Direction::Down;
          coords.row += 1;
        }
        else
          return result;
        break;
      case Down:
        if (coords.row + 1 < numOfRows && mapOfMatrix[coords.row + 1][coords.col] == 0)
          coords.row += 1;
        else if (coords.col - 1 >= 0 && mapOfMatrix[coords.row][coords.col - 1] == 0) {
          dir = Direction::Left;
          coords.col -= 1;
        }
        else
          return result;
        break;
      case Left:
        if (coords.col - 1 >= 0 && mapOfMatrix[coords.row][coords.col - 1] == 0)
          coords.col -= 1;
        else if (coords.row - 1 >= 0 && mapOfMatrix[coords.row - 1][coords.col] == 0) {
          dir = Direction::Up;
          coords.row -= 1;
        }
        else
          return result;
        break;
      case Up:
        if (coords.row - 1 >= 0 && mapOfMatrix[coords.row - 1][coords.col] == 0)
          coords.row -= 1;
        else if (coords.col + 1 < numOfCols && mapOfMatrix[coords.row][coords.col + 1] == 0) {
          dir = Direction::Right;
          coords.col += 1;
        }
        else
          return result;
        break;
      }
    }
  }
};
int main() {
  return 0;
}
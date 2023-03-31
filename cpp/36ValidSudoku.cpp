class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (const auto& row : board) {
      if (!isArrayValid(row))
        return false;
    }
    vector<char> test;
    test.reserve(9);
    for (int j = 0; j < board.size(); ++j) {
      test.clear();
      for (int i = 0; i < board.size(); ++i) {
        test.push_back(board[i][j]);
      }
      if (!isArrayValid(test))
        return false;
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        test.clear();
        for (int iInner = 0; iInner < 3; ++iInner)
          for (int jInner = 0; jInner < 3; ++jInner)
            test.push_back(board[3 * i + iInner][j * 3 + jInner]);
        if (!isArrayValid(test))
          return false;
      }
    }
    return true;
  }

  bool isArrayValid(const vector<char>& iArr) {

    for (auto c : iArr) {
      if (c == '.')
        continue;
      if (c < '1' || c > '9')
        return false;
      if (validator.count(c))
        return false;
      else
        validator.emplace(c);
    }
    return true;
  }
};
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    result.reserve(pow(4, digits.size()));
    for (auto c : digits) {
      vector<char> newLetters;
      switch (c)
      {
      case '2':
        newLetters = { 'a', 'b', 'c' };
        break;
      case '3':
        newLetters = { 'd', 'e', 'f' };
        break;
      case '4':
        newLetters = { 'g', 'h', 'i' };
        break;
      case '5':
        newLetters = { 'j', 'k', 'l' };
        break;
      case '6':
        newLetters = { 'm', 'n', 'o' };
        break;
      case '7':
        newLetters = { 'p', 'q', 'r', 's' };
        break;
      case '8':
        newLetters = { 't', 'u', 'v' };
        break;
      case '9':
        newLetters = { 'w', 'x', 'y', 'z' };
        break;
      default:
        continue;
        break;
      }
      if (result.empty()) {
        for (auto c: newLetters) {
          result.push_back({ c });
        }
        continue;
      }
      for (auto& str : result) {
        for (int i = 1; i < newLetters.size(); ++i) {
          result.push_back(str + newLetters[i]);
        }
        str += newLetters[0];
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  s.letterCombinations("23");
}
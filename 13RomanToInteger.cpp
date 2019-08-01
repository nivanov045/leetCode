//  13. Roman to Integer
//  Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <map>

class Solution {
public:
  int romanToInt(std::string s) {

  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::string, int> tests = {
    {"III", 3},
    {"IV", 4},
    {"IX", 9},
    {"LVIII", 58},
    {"MCMXCIV", 1994},
  };
  for (auto test : tests) {
    if (sol.romanToInt(test.first) != test.second) {
      std::cout << "Mistake at test with input" << test.first << std::endl;
      system("pause");
    }
  }
  return 0;
}
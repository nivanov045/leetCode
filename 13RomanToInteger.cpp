//  13. Roman to Integer
//  Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <map>
#include <sstream>

class Solution {
public:
  int romanToInt(std::string s) {
    std::stringstream ss(s);
    char curSymb;
    char nextSymb;
    int result = 0;
    while (ss.get(curSymb)) {
      switch (curSymb)
      {
      case 'I':
        if (!ss.peek()) {
          result += 1;
          return result;
        }
        nextSymb = ss.peek();
        if (nextSymb == 'V' || nextSymb == 'X')
          result -= 1;
        else
          result += 1;
        break;
      case 'V':
        result += 5;
        break;
      case 'X':
        if (!ss.peek()) {
          result += 1;
          return result;
        }
        nextSymb = ss.peek();
        if (nextSymb == 'L' || nextSymb == 'C')
          result -= 10;
        else
          result += 10;
        break;
      case 'L':
        result += 50;
        break;
      case 'C':
        if (!ss.peek()) {
          result += 1;
          return result;
        }
        nextSymb = ss.peek();
        if (nextSymb == 'D' || nextSymb == 'M')
          result -= 100;
        else
          result += 100;
        break;
      case 'D':
        result += 500;
        break;
      case 'M':
        result += 1000;
        break;
      default:
        break;
      }
    }
    return result;
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
//  38. Count and Say
//  Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. 
//  Note: Each term of the sequence of integers will be represented as a string.
#include <iostream>
#include <string>
#include <map>

class Solution {
public:
  std::string parseToNext(const std::string& iStr) const
  {
    auto curIdx = 0u;
    auto result = std::string();
    auto curCounter = 0;
    auto curNumber = char();
    auto reset = true;
    while (curIdx < iStr.size()) {
      if (reset) {
        if (curCounter > 0) {
          result += std::to_string(curCounter);
          result += curNumber;
        }
        reset = false;
        curCounter = 1;
        curNumber = iStr[curIdx];
      }
      else {
        ++curIdx;
        if (curIdx < iStr.size() && iStr[curIdx] == curNumber)
          ++curCounter;
        else {
          reset = true;
        }
      }
    }
    result += std::to_string(curCounter);
    result += curNumber;
    return result;
  }
  std::string countAndSay(int n) {
    if (n == 1)
      return std::to_string(1);
    auto prevStr = std::to_string(1);
    for (int i = 2; i <= n; ++i) {
      prevStr = parseToNext(prevStr);
    }
    return prevStr;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<int, std::string> tests = {
    {1, "1"},
    {2, "11"},
    {3, "21"},
    {4, "1211"},
    {5, "111221"}
  };
  for (const auto& test : tests) {
    if (sol.countAndSay(test.first) != test.second) {
      std::cout << "Mistake at test with input: " << test.first << std::endl;
      system("pause");
    }
  }
  return 0;
}
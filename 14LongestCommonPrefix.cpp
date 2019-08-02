//  14. Longest Common Prefix
//  Write a function to find the longest common prefix string amongst an array of strings.
//  If there is no common prefix, return an empty string "".

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>


class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string result = "";
    if (strs.empty())
      return result;
    size_t curIdx = 0;
    while (curIdx < strs[0].length()) {
      char curSymb = strs[0][curIdx];
      for (size_t wordIdx = 1; wordIdx < strs.size(); ++wordIdx ) {
        if (strs[wordIdx].size() == curIdx || strs[wordIdx][curIdx] != curSymb)
          return result;
      }
      result += curSymb;
      ++curIdx;
    }
    return result;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::vector<std::string>, std::string> tests = {
    {{"fli", "flower","flow","flight"}, "fl" },
    {{}, "" },
    {{"dog","racecar","car"}, "" }
  };
  for (auto test : tests) {
    std::vector<std::string> curVr = test.first;
    if (sol.longestCommonPrefix(curVr) != test.second) {
      std::cout << "Mistake at test with input: " << test.first.front() << std::endl;
      system("pause");
      return 1;
    }
  }
  return 0;
}
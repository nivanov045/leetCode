//  3. Longest Substring Without Repeating Characters
//  Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <list>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::list<char> storage;
    size_t curIdx = 0;
    size_t result = 0;
    while (curIdx < s.size()) {
      char curSymbol = s[curIdx];
      auto it = std::find(storage.begin(), storage.end(), curSymbol);
      if (it != storage.end()) {
        storage.erase(storage.begin(), ++it);
      }
      storage.emplace_back(s[curIdx]);
      result = std::max(result, storage.size());
      ++curIdx;
    }
    return result;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::string, int> tests = {
    {"aabaab!bb", 3},
    {"dvdf", 3},
    {"aab", 2},
    {"abcabcbb", 3},
    {"bbbbb", 1},
    {"pwwkew", 3}
  };
  for (auto test : tests) {
    if (sol.lengthOfLongestSubstring(test.first) != test.second) {
      std::cout << "Mistake at test with input: " << test.first << std::endl;
      system("pause");
    }
  }
  return 0;
}
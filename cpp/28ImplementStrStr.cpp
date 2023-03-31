//  28. Implement strStr()
//  Implement strStr(). Return the index of the first occurrence of needle in haystack, or -1 if needle is not part 
//  of haystack. Return 0 when needle is an empty string.
#include <iostream>
#include <string>
#include <map>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty())
      return 0;
    auto hIdx = 0u;
    std::pair<bool, uint32_t> hNxtIdx = { false, 0u };
    while (hIdx + needle.size() <= haystack.size() + 1) {
      if (haystack[hIdx] == needle[0]) {
        auto nIdx = 1u;
        ++hIdx;
        while (hIdx < haystack.size() && nIdx < needle.size() && haystack[hIdx] == needle[nIdx]) {
          if (!hNxtIdx.first && haystack[hIdx] == needle[nIdx])
            hNxtIdx = { true, hIdx };
          ++hIdx;
          ++nIdx;
        }
        if (nIdx == needle.size())
          return hIdx - needle.size();
        if (hNxtIdx.first) {
          hNxtIdx.first = false;
          hIdx = hNxtIdx.second;
        }
      }
      else
        ++hIdx;
    }
    return -1;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::pair<std::string, std::string>, int> tests = {
    {{"Hello", "ll"}, 2},
    {{"Helloll", "ll"}, 2},
    {{"mississippi", "issip"}, 4},
    {{"aabaaabaaac","aabaaac" }, 4},
    {{"", ""}, 0},
    {{"Hello", ""}, 0},
    {{"aaaaa", "bba"}, -1},
    {{"", "bba"}, -1}
  };
  for (const auto& test : tests) {
    if (sol.strStr(test.first.first, test.first.second) != test.second) {
      std::cout << "Mistake at test with input: " << test.first.first << std::endl;
      system("pause");
    }
  }
  return 0;
}
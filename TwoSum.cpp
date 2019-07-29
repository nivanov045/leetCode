// 1. Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> vecProx;
    for (int idx = 0; idx < nums.size(); ++idx)
      vecProx.emplace_back(nums[idx], idx);
    std::sort(vecProx.begin(), vecProx.end(), [](std::pair<int, size_t> lhs, std::pair<int, size_t> rhs)
    {
      return lhs.first < rhs.first;
    });
    int firstIdx = 0;
    int lastIdx = vecProx.size() - 1;
    for (;;) {
      while (vecProx[lastIdx].first + vecProx[firstIdx].first > target)
        --lastIdx;
      if (vecProx[lastIdx].first + vecProx[firstIdx].first == target)
        return { vecProx[firstIdx].second, vecProx[lastIdx].second };
      ++firstIdx;
    }
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::vector<int> vec = { 2, 7, 11, 15 };
  auto res = sol.twoSum(vec, 9);
  //vec = { 3, 2, 4 };
  //res = sol.twoSum(vec, 6);
  std::cout << res[0] << ' ' << res[1] << std::endl;
  system("pause");
  return 0;
}

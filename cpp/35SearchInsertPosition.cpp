//  35. Search Insert Position
//  Given a sorted array and a target value, return the index if the target is found. If not, return the index where
//  it would be if it were inserted in order. You may assume no duplicates in the array.
#include <algorithm>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};

int main(int argc, char* argv[])
{
  return 0;
}
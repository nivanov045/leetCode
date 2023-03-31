class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto firstIter = lower_bound(nums.begin(), nums.end(), target);
    if (firstIter == nums.end() || *firstIter != target)
      return { -1, -1 };
    int firstIdx = firstIter - nums.begin(), lastIdx = (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1;
    return { firstIdx, lastIdx };
  }
};
class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty())
      return -1;
    int idxLeft = 0, idxRight = nums.size() - 1;
    if (nums[idxLeft] <= nums[idxRight]) {
      auto it = lower_bound(nums.begin(), nums.end(), target);
      if (it == nums.end() || *it != target)
        return -1;
      else
        return it - nums.begin();
    }
    int pivot = 0;
    while (idxRight > idxLeft + 1) {
      int idx = (idxRight + idxLeft) / 2;
      if (nums[idx] > nums[nums.size() - 1]) {
        if (nums[idx + 1] < nums[idx]) {
          pivot = idx;
          break;
        }
        else {
          idxLeft = idx;
        }
      }
      else {
        if (nums[idx - 1] > nums[idx]) {
          pivot = idx - 1;
          break;
        }
        else {
          idxRight = idx;
        }
      }
    }
    if (idxRight == idxLeft + 1)
      pivot = idxLeft;
    if (target > nums[nums.size() - 1]) {
      idxLeft = 0;
      idxRight = pivot + 1;
    }
    else {
      idxLeft = pivot + 1;
      idxRight = nums.size();
    }
    auto it = lower_bound(nums.begin() + idxLeft, nums.begin() + idxRight, target);
    if (it == nums.end() || *it != target)
      return -1;
    else
      return it - nums.begin();
  }
};
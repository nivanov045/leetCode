class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() == 0)
      return result;
    if (nums.size() == 1) {
      result.push_back(nums);
      return result;
    }
    for (int i = 0; i < nums.size(); ++i) {
      auto el = nums[i];
      nums.erase(nums.begin() + i);
      auto perm = permute(nums);
      for (int j = 0; j < perm.size(); ++j) {
        perm[j].push_back(el);
      }
      nums.insert(nums.begin() + i, el);
      result.insert(result.end(), perm.begin(), perm.end());
    }
    return result;
  }
};
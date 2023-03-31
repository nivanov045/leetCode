#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4)
      return result;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size() - 3) {
      int l = nums.size() - 1;
      while (l > i + 2 && nums[i] + nums[i + 1] + nums[i + 2] + nums[l] > target)
        --l;
      while (l > i + 2) {
        int j = i + 1, k = l - 1;
        while (j != k) {
          auto sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum < target) {
            auto cur = nums[j];
            while (j != k && nums[j] == cur)
              ++j;
          }
          else if (sum >= target) {
            if (sum == target)
              result.push_back(vector<int>({ nums[i], nums[j], nums[k], nums[l] }));
            auto cur = nums[k];
            while (j != k && nums[k] == cur)
              --k;
          }
        }
        auto cur = nums[l];
        while (l > i + 2 && nums[l] == cur)
          --l;
      }
      auto cur = nums[i];
      while (i < nums.size() - 3 && nums[i] == cur)
        ++i;
    }
    return result;
  }
};

int main() {
  Solution s;
  
}
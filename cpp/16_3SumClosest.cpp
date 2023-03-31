#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i)
      for (int j = i + 1; j < nums.size() - 1; ++j)
        for (int k = nums.size() - 1; k > j; --k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == target)
            return target;
          if (abs(target - result) > abs(target - sum))
            result = sum;
          if (sum < target)
            break;
        }
    return result;
  }
};
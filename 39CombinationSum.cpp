#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (_storage.count(target))
      return(_storage[target]);
    vector<vector<int>> result;
    for (auto candidate : candidates) {
      if (candidate > target)
        continue;
      if (candidate == target) {
        result.push_back({candidate});
        continue;
      }
      auto curRes = combinationSum(candidates, target - candidate);
      if (curRes.empty())
        continue;
      for (auto& res : curRes) {
        res.emplace(upper_bound(res.begin(), res.end(), candidate), candidate);
        if (find(result.begin(), result.end(), res) == result.end())
          result.push_back(res);
      }
    }
    _storage[target] = result;
    return result;
  }
private:
  unordered_map<int, vector<vector<int>>> _storage;
};

int main() {
  Solution s;
  vector<int> testC = { 2, 3, 5, 8 };
  int testT = 8;
  auto r = s.combinationSum(testC, testT);
  return 0;
}
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
    if (!_sorted) {
      sort(candidates.begin(), candidates.end());
      _sorted = true;
    }
    for (int i = 0; i < candidates.size(); ++i) {
      auto candidate = candidates[i];
      if (candidate > target)
        break;
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
  bool _sorted = false;
};

int main() {
  Solution s;
  vector<int> testC = { 2, 3, 5, 8 };
  int testT = 8;
  auto r = s.combinationSum(testC, testT);
  return 0;
}
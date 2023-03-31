#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (!_isPreparedData) {
      sort(candidates.begin(), candidates.end());
      for (auto c : candidates) {
        ++_candidatesMap[c];
      }
      _isPreparedData = true;
    }
    vector<vector<int>> result;
    if (_storage.count(target)) {
      for (auto sol : _storage[target]) {
        bool canUseSol = true;
        for (auto el : sol) {
          if (!_candidatesMap.count(el) || _candidatesMap[el] <= 0) {
            canUseSol = false;
            break;
          }
          else
            --_candidatesMap[el];
        }
        if (!canUseSol)
          continue;
        result.push_back(sol);
      }
    }
    for (int i = 0; i < candidates.size(); ++i) {
      auto candidate = candidates[i];
      if (candidate == -1) {
        continue;
      }
      if (candidate > target)
        break;
      if (candidate == target) {
        auto can = vector<int>({ candidate });
        if (find(result.begin(), result.end(), can) == result.end())
          result.push_back(can);
        continue;
      }
      auto stored = candidate;
      --_candidatesMap[stored];
      candidates[i] = -1;
      auto curRes = combinationSum2(candidates, target - candidate);
      candidates[i] = stored;
      ++_candidatesMap[stored];
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
  bool _isPreparedData = false;
  unordered_map<int, int> _candidatesMap;
};

int main() {
  Solution s;
  vector<int> testC = { 4,4,2,1,4,2,2,1,3 };
  int testT = 6;
  auto r = s.combinationSum2(testC, testT);
  return 0;
}
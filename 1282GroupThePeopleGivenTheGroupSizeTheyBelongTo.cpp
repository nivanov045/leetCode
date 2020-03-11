class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        std::vector<std::vector<int>> result;
        std::unordered_map<int, std::vector<int>> tmpBase;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (!tmpBase.count(groupSizes[i])) {
                tmpBase[groupSizes[i]] = std::vector<int>();
                tmpBase[groupSizes[i]].reserve(groupSizes[i]);
            }
            tmpBase[groupSizes[i]].push_back(i);
            if (tmpBase[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(tmpBase[groupSizes[i]]);
                tmpBase[groupSizes[i]].clear();
            }
        }
        return result;
    }
};
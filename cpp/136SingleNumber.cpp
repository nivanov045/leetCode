class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> database;
        for (auto num: nums) {
            if (database.count(num))
                database.erase(num);
            else
                database.insert(num);
        }
        return *database.begin();
    }
};
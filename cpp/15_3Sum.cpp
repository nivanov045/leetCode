class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> db;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            int l = i+1, r = nums.size() - 1;
            while (l < r) {
                if (-nums[i] < nums[l] + nums[r]) {
                    auto cur = nums[r];
                    while ((l < r) && cur == nums[r])
                        --r;
                }
                else if (-nums[i] > nums[l] + nums[r]) {
                    auto cur = nums[l];
                    while ((l < r) && cur == nums[l])
                        ++l;
                }
                else {
                    db.insert({nums[i], nums[l], nums[r]});
                    auto cur = nums[l];
                    while ((l < r) && cur == nums[l])
                        ++l;
                    cur = nums[r];
                    while ((l < r) && cur == nums[r])
                        --r;
                }
            }
            auto cur = nums[i];
            while (i < nums.size() && cur == nums[i])
                ++i;
        }
        return vector<vector<int>>(db.begin(), db.end());
    }
};
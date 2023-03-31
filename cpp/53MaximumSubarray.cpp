class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = -1;
        for (auto num: nums) {
            if (sum <= 0)
                sum = num;
            else
                sum += num;
            if (result < sum)
                result = sum;
        }
        return result; 
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty())
            return result;
        int itFirst = 0, itLast = 0;
        int first = nums[itFirst], last = nums[itLast];
        while (itFirst < nums.size()) {
            while (itLast < nums.size() && (itLast == itFirst || nums[itLast - 1] + 1 == nums[itLast]))
                ++itLast;
            stringstream s;
            s << nums[itFirst];
            if (itFirst != itLast - 1)
                s << "->" << nums[itLast - 1];
            result.push_back(s.str());
            itFirst = itLast;
        }
        return result;
    }
};

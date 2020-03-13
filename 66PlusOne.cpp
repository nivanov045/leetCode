class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        result.reserve(digits.size() + 1);
        int additional = 1;
        int it = digits.size() - 1;
        do {
            int sum = (digits[it] + additional);
            result.push_back(sum % 10);
            if (sum >= 10)
                additional = 1;
            else
                additional = 0;
            --it;
        } while (it >= 0);
        if (additional == 1)
            result.push_back(1);
        std::reverse(result.begin(), result.end()); 
        return result;
    }
};

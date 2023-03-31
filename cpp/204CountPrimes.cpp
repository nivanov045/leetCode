class Solution {
public:
    int countPrimes(int n) {
        std::vector<int> result(n, 1);
        int numRes = 0;
        for (int i = 2; i < n; ++i) {
            if (result[i] == -1)
                continue;
            ++numRes;
            for (int idx = i + i; idx < result.size(); idx += i)
                result[idx] = -1;
        }
        return numRes;
    }
};
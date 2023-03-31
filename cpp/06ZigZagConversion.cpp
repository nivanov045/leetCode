class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string result;
        int dividor = (numRows - 1) * 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (j % dividor == i || j % dividor == dividor - i)
                    result.push_back(s[j]);
            }
        }
        return result;
    }
};
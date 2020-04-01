class Solution {
public:
    char charFromInt(int n) {
        return (char)((int)'A' + n);
    }
    
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
            --n;
            auto x = n % 26;
            s.insert(0, 1, charFromInt(x));
            n = n / 26;
        }
        return s;
    }
};
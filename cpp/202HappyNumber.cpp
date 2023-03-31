class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> db;
        while (n != 1 && !db.count(n)) {
            db.insert(n);
            n = transform(n);
        }
        return n == 1;
    }
    
    int transform(int n) {
        int result = 0;
        while (n != 0) {
            result += (n % 10) * (n % 10);
            n = n / 10;
        }
        return result;
    }
};
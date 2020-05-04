class Solution {
public:
  double myPow(double x, int n) {
    auto result = 1.0;
    if (n == 0)
      return result;
    unordered_map<int, double> db;
    if (n > 0) {
      int i = 1;
      result = abs(x);
      db[i] = abs(x);
      while (i < n / 2) {
        result *= result;
        i *= 2;
        db[i] = result;
      }
      int j = i;
      while (i < n) {
        while (j > n - i)
          j /= 2;
        result *= db[j];
        i += j;
      }
    }
    else {
      int i = -1;
      result = 1.0 / abs(x);
      db[i] = 1.0 / abs(x);
      while (i > n / 2) {
        result *= result;
        i *= 2;
        db[i] = result;
      }
      int j = i;
      while (i > n) {
        while (j < n - i)
          j /= 2;
        result *= db[j];
        i += j;
      }
    }
    if (x < 0 && n % 2 != 0)
      result *= -1;
    return result;
  }
};
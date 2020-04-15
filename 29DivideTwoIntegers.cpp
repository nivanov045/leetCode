class Solution {
public:
  int divide(int dividend, int divisor) {
    auto isDivisorPos = divisor > 0;
    auto isDividendPos = dividend > 0;
    if (divisor == -2147483648)
      if (dividend == -2147483648)
        return 1;
      else
        return 0;
    divisor = abs(divisor);
    vector<pair<int, int>> database;
    database.push_back({ 1, divisor });
    int curIdx = 0;
    int res = 0;
    bool canIncrease = true;
    while (curIdx >= 0) {
      while ((isDividendPos && dividend >= database[curIdx].second)
        || (!isDividendPos && dividend <= -database[curIdx].second)) {
        if (2147483647 - database[curIdx].first >= res)
          res += database[curIdx].first;
        else {
          return ((isDivisorPos && !isDividendPos) || (!isDivisorPos && isDividendPos) ? -2147483648 : 2147483647);
        }
        if (isDividendPos)
          dividend -= database[curIdx].second;
        else
          dividend += database[curIdx].second;
        if (canIncrease) {
          if (database[curIdx].second < 1073741824) {
            database.push_back({ database[curIdx].first + database[curIdx].first, database[curIdx].second + database[curIdx].second });
            ++curIdx;
          }
          else
            canIncrease = false;
        }
      }
      canIncrease = false;
      --curIdx;
    }
    return ((isDivisorPos && isDividendPos) || (!isDivisorPos && !isDividendPos) ? res : -res);
  }
};
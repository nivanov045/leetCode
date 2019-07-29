// 7. Reverse Integer
// Given a 32 - bit signed integer, reverse digits of an integer.

#include <limits>
#include <cstdint>
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int multipl = x < 0 ? -1 : 1;
    int result = 0;
    while (x != 0) {
      // check that we can add digit
      int curNumber = abs(x % 10);
      if ((multipl > 0 && result > std::numeric_limits<int>::max() / 10) ||
        (multipl < 0 && result < -std::numeric_limits<int>::max() / 10))
        return 0;
      result *= 10;
      if ((multipl > 0 && result >= std::numeric_limits<int>::max() - curNumber) ||
        (multipl < 0 && result <= -std::numeric_limits<int>::max() + curNumber))
        return 0;
      result += (curNumber * multipl);
      x /= 10;
    }
    return result;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  if (sol.reverse(123) != 321)
    std::cout << sol.reverse(123) << std::endl;
  if (sol.reverse(-123) != -321)
    std::cout << sol.reverse(-123) << std::endl;
  if (sol.reverse(120) != 21)
    std::cout << sol.reverse(120) << std::endl;
  if (sol.reverse(1463847412) != 2147483641)
    std::cout << sol.reverse(1463847412) << std::endl;
  system("pause");
  return 0;
}

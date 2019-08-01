//  9. Palindrome Number
//  Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    std::string s = std::to_string(x);
    size_t firstIt = 0;
    size_t lastIt = s.size() - 1;
    while (firstIt < lastIt && s[firstIt] == s[lastIt]) {
      ++firstIt;
      --lastIt;
    }
    return s[firstIt] == s[lastIt];
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  int x = 10501;
  if (sol.isPalindrome(x) != true)
    std::cout << x << std::endl;
  system("pause");
  return 0;
}
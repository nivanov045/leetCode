#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isNum(char c) {
    return '0' <= c && c <= '9';
  }

  int charToNum(char c) {
    return c - '0';
  }

  int myAtoi(string str) {
    int idx = 0;
    while (idx < str.size() && (str[idx] == ' '))
      ++idx;
    if (idx == str.size() || (!isNum(str[idx]) && str[idx] != '-' && str[idx] != '+'))
      return 0;
    int result = 0;
    bool negative = str[idx] == '-';
    int boundary = (negative ? INT_MIN : INT_MAX);
    int counter = 0;
    while ((negative && boundary < 0) || (!negative && boundary > 0)) {
      ++counter;
      boundary /= 10;
    }
    if (negative || str[idx] == '+')
      ++idx;
    while (idx < str.size() && (str[idx] == '0'))
      ++idx;
    int numOfDigits = 0;
    while (idx < str.size() && numOfDigits < counter - 1) {
      if (!isNum(str[idx]))
        break;
      result *= 10;
      result += charToNum(str[idx]);
      ++idx;
      ++numOfDigits;
    }
    if (numOfDigits != counter - 1 || idx == str.size() || !isNum(str[idx])) {
      return result * (negative ? -1 : 1);
    }
    if (idx + 1 < str.size() && isNum(str[idx + 1]))
      return (negative ? INT_MIN : INT_MAX);
    if ((negative && -result < INT_MIN / 10) || (!negative && result > INT_MAX / 10) ||
      (((negative && -result == INT_MIN / 10) || (!negative && result == INT_MAX / 10)) &&
        charToNum(str[idx]) >= abs(negative ? INT_MIN : INT_MAX) % 10)) {
      return (negative ? INT_MIN : INT_MAX);
    }
    return (result * 10 + charToNum(str[idx])) * (negative ? -1 : 1);
  }
};
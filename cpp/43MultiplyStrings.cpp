#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1.size() < num2.size())
      num1.swap(num2);
    string result;
    result.reserve(220);
    string curResult;
    curResult.reserve(220);
    for (int idx2 = num2.size() - 1; idx2 >= 0; --idx2) {
      auto curRes = multiply(num1, num2[idx2]);
      curResult = add(curRes, curResult);
      result += curResult.back();
      curResult.pop_back();
    }
    std::reverse(result.begin(), result.end());
    result = curResult.append(result);
    return result;
  }
private:
  int ctoi(char c) {
    return ((int)c - (int)'0');
  }

  char itoc(int i) {
    return (char)((int)'0' + i);
  }

  string multiply(string num1, char c) {
    string result;
    result.reserve(111);
    auto cAsNum = ctoi(c);
    int addedFromPrev = 0;
    for (int idx1 = num1.size() - 1; idx1 >= 0; --idx1) {
      int r = ctoi(num1[idx1]) * cAsNum + addedFromPrev;
      if (r >= 10) {
        addedFromPrev = r / 10;
        r %= 10;
      }
      else
        addedFromPrev = 0;
      result += itoc(r);
    }
    if (addedFromPrev)
      result += itoc(addedFromPrev);
    std::reverse(result.begin(), result.end());
    return result;
  }

  string add(string num1, string num2) {
    string result;
    result.reserve(111);
    int addedFromPrev = 0;
    for (int i = 0; i < max(num1.size(), num2.size()); ++i) {
      auto first = num1.size() >= 1 + i ? ctoi(num1[num1.size() - 1 - i]) : 0;
      auto second = num2.size() >= 1 + i ? ctoi(num2[num2.size() - 1 - i]) : 0;
      int r = first + second + addedFromPrev;
      if (r >= 10) {
        addedFromPrev = 1;
        r -= 10;
      }
      else
        addedFromPrev = 0;
      result += itoc(r);
    }
    if (addedFromPrev == 1) {
      result += itoc(1);
    }
    while (result.length() > 1 && result.back() == '0') {
      result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution s;
  cout << s.multiply("0", "789") << endl;
  system("pause");
  return 0;
}
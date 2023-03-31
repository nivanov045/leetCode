//  20. Valid Parentheses
//  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is 
//  valid. An input string is valid if:
//    Open brackets must be closed by the same type of brackets.
//    Open brackets must be closed in the correct order.
//  Note that an empty string is also considered valid.

#include <iostream>
#include <string>
#include <map>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> order;
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[')
        order.push(c);
      else {
        if (order.empty())
          return false;
        if (c == ')' && order.top() != '(')
          return false;
        if (c == '}' && order.top() != '{')
          return false;
        if (c == ']' && order.top() != '[')
          return false;
        order.pop();
      }
    }
    return order.empty();
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::string, bool> tests = {
    {"()", true },
    {"", true },
    {"()[]{}", true },
    {"(]", !true },
    {"([)]", !true },
    {"]", !true },
    {"[", !true },
    {"{[]}", true }
  };
  for (const auto& test : tests) {
    if (sol.isValid(test.first) != test.second) {
      std::cout << "Mistake at test with input: " << test.first << std::endl;
      system("pause");
    }
  }
  return 0;
}
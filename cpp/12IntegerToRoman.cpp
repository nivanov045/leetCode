class Solution {
public:
  string intToRoman(int num) {
    std::vector<std::pair<int, string>> nums = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
    std::string res = "";
    for (auto p : nums) {
      for (int i = 0; i < num / p.first; ++i)
        res += p.second;
      num = num % p.first;
    }
    return res;
  }
};
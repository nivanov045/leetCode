//  4. Median of Two Sorted Arrays
//  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <string>
#include <map>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    const auto elsAtAll = nums1.size() + nums2.size();
    const bool needEl = elsAtAll % 2;
    int el = 0;
    size_t idx1 = 0, idx2 = 0;
    for (size_t curElIdx = 0; curElIdx != (elsAtAll / 2 + needEl); ++curElIdx) {
      if (idx1 == nums1.size()) {
        el = nums2[idx2];
        ++idx2;
        continue;
      }
      if (idx2 == nums2.size()) {
        el = nums1[idx1];
        ++idx1;
        continue;
      }
      if (nums1[idx1] <= nums2[idx2])  {
        el = nums1[idx1];
        ++idx1;
      }
      else {
        el = nums2[idx2];
        ++idx2;
      }
    }
    if (needEl)
      return el;
    int el2 = 0;
    if (idx1 == nums1.size()) {
      el2 = nums2[idx2];
    }
    else if (idx2 == nums2.size()) {
      el2 = nums1[idx1];
    }
    else if (nums1[idx1] <= nums2[idx2]) {
      el2 = nums1[idx1];
    }
    else {
      el2 = nums2[idx2];
    }
    return (el + el2) / 2.0;
  }
};

int main(int argc, char* argv[])
{
  Solution sol;
  std::map<std::pair<std::vector<int>, std::vector<int>>, double> tests = {
    {{{1, 3}, {2}}, 2.0 },
    {{{1, 2}, {3, 4}}, 2.5 }
  };
  for (auto test : tests) {
    if (sol.findMedianSortedArrays(test.first.first, test.first.second) != test.second) {
      std::cout << "Mistake at test with input: " << test.second << std::endl;
      system("pause");
    }
  }
  return 0;
}
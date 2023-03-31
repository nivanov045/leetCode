//  26. Remove Duplicates from Sorted Array
//  Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return 
//  the new length. Do not allocate extra space for another array, you must do this by modifying the input array
//  in - place with O(1) extra memory.

#include <vector>
#include <algorithm>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
  }
};

int main(int argc, char* argv[])
{
  return 0;
}
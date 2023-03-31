class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    //next_permutation(nums.begin(), nums.end());
    int idxRight = nums.size() - 1;
    int idxLeft = nums.size() - 1;
    int minInRange = nums[nums.size() - 1];
    while (idxLeft >= 0) {
      idxRight = idxLeft + 1;
      bool isBiggerExist = false;
      int minBiggerIdx = 0;
      while (idxRight < nums.size()) {
        if (nums[idxLeft] < nums[idxRight]) {
          if (!isBiggerExist) {
            minBiggerIdx = idxRight;
            isBiggerExist = true;
          }
          else
            if (nums[idxRight] < nums[minBiggerIdx])
              minBiggerIdx = idxRight;
        }
        ++idxRight;
      }
      if (isBiggerExist) {
        swap(nums[idxLeft], nums[minBiggerIdx]);
        sort(nums.begin() + idxLeft + 1, nums.end());
        return;
      }
      --idxLeft;
    }
    idxLeft = 0;
    idxRight = nums.size() - 1;
    while (idxLeft < idxRight) {
      swap(nums[idxRight], nums[idxLeft]);
      --idxRight;
      ++idxLeft;
    }
  }
};
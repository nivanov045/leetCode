class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int idxl = 0, idxr = height.size() - 1;
        while (idxl != idxr){
            bool lefLower = height[idxl] < height[idxr];
            result = std::max(result, (lefLower ? height[idxl] : height[idxr]) * (idxr-idxl));
            if (lefLower)
                ++idxl;
            else
                --idxr;
        }
        return result;
    }
};
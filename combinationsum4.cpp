class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<unsigned int> arr(target + 1, 0);
        arr[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    arr[i] += arr[i - num];
                }
            }
        }
        
        return arr[target];
    }
};
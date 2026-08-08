

class Solution {
public:
    int rob(vector<int>& nums) {
        // Max
        if (nums.size() == 1) return nums[0];
        int n = nums.size() ;
        int prev2 = nums[0];
        int prev1 = max(nums[1],nums[0]);
        for (int i = 2; i < n ; i++) {
            int temp = prev1;
            prev1 = max(prev1 , nums[i] + prev2 );
            prev2 = temp;
        }
        return prev1;
    }
};

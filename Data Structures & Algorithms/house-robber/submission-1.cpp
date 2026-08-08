class Solution {
public:
    int rob(vector<int>& nums) {
        // Max
        if (nums.size() == 1) return nums[0];
        int n = nums.size() ;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for (int i = 2; i < n ; i++) {
            dp[i] = max(dp[i-1] , nums[i] + dp[i-2]);
        }
        return dp[nums.size() - 1];
    }
};

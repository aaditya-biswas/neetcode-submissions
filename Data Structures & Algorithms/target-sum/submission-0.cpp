class Solution {
private:
    int calc(int ind, int target ,vector<int> & nums) {
        if (ind < 0) return target == 0;
        if (dp[ind].contains(target)) return dp[ind][target];
        // Take positive
        int left = calc(ind-1,target - nums[ind] ,nums );
        
        // Take negative
        int right = calc(ind - 1,target + nums[ind] ,nums);
        return dp[ind][target] = left + right;
    }
    vector<unordered_map<int,int>> dp;
public:

    inline int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n);
        return calc(n - 1, target ,nums);
    }
};

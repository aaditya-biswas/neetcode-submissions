class Solution {
public:
    using ll = long long;
    bool canPartition(vector<int>& nums) {
        // Partition equal subset sum
        // Let dp[i][sum ] indicate that whether we can reach the target sum  from the indices 0 ... i
        // Base case dp[i][0] = 1;
        // dp[0][nums[0]] = 1;
        int n = nums.size();
        ll sum  = accumulate(nums.begin() , nums.end()  ,0); 
        if (sum % 2) return false;
        vector<vector<int>> dp( n , vector<int> (sum +1  , 0));
        for (int i =  0 ; i < n ;  ++i) {
            dp[i][0] = 1;
        } 
        dp[0][nums[0]] = 1;
        for (int i = 1 ; i < n ; i++ ) {
            for (int j = 0 ; j <= sum; j++ ) {
                if (j - nums[i] >= 0) dp[i][j]  = max(dp[i-1][j],dp[i-1][j - nums[i] ]);
                else dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
        return dp[ n- 1][ sum /2 ];    
    }
};

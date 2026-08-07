class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto & m : coins) {
            if (m > amount) continue;
           dp[m] = 1;
        } 
        for (int i = 1 ; i <=  amount ;i++) {
            for (auto & m : coins) {
                if (i - m < 0 || dp[i - m] == INT_MAX) continue;
                dp[i] = min(dp[i] , 1 + dp[i-m]);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

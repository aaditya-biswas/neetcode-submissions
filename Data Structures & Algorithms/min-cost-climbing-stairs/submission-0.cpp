class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+ 2,INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2 ; i < cost.size() + 2 ; i++) {
            if (i - 1 < cost.size()) dp[i] = dp[i-1]+ cost[i-1];
            if  (i - 2 < cost.size()) dp[i] = min(dp[i],dp[i-2 ]+ cost[i-2]);
            
        }
        return min(dp[cost.size()], dp[cost.size() + 1]);

        
    }
};

#include <cstring>  // Recommended for C++
class Solution {
private:
    int calculate(int ind, int target, vector<int>  & coins) {
        if (target == 0) return 1; 
        if (ind < 0) return 0;
        if (dp[ind][target ] != -1 ) return dp[ind][target];
        // Do no take 
        int ans = 0;
        ans += calculate(ind - 1,target, coins);
        for (int i = coins[ind]; i <= target ; i += coins[ind]) {
            ans += calculate(ind -1, target - i , coins);
        }
        return dp[ind][target] = ans;
    }
public:
    int dp[101][5001];
    int change(int amount, vector<int>& coins) {
        memset(dp , -1 ,sizeof(dp));
        int n = coins.size();
        return calculate(n - 1, amount, coins);


    }
};

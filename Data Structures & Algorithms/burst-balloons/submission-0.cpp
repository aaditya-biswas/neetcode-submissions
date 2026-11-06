#include <string.h>
class Solution {
private:
    int dp[305][305];
    int calc(int l , int r , vector<int> & nums) {
        if (l > r) return 0; 
        int left = ((l - 1 < 0 ) ? 1 : nums[l - 1]);
        int right = ((r + 1 >= nums.size()) ? 1 :nums[ r + 1]);

        if (l == r) return nums[l] * left * right ;
        if (dp[l][r] != -1) return dp[l][r];
        int maxCoins = 0;
        for (int i = l ; i <= r; ++i) {
            // Choose
            maxCoins = max(nums[i] * left * right  + calc(l , i -1, nums) + calc(i + 1, r, nums), maxCoins);
        }
        return dp[l][r] = maxCoins;

    }
public:
    int maxCoins(vector<int>& nums) {
        memset(dp, -1 , sizeof(dp));
        return calc(0 , nums.size() - 1, nums);
    }
};

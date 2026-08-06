class Solution {
public:
    int rob(vector<int>& nums) {
        // Start from the first house and start robbing
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size() , 0);
        vector<int> dp2(nums.size(), 0);
        dp1[0] = nums[0];
        dp1[1] =  nums[0];
        for (int i = 2; i < n - 1;   i++) {
            dp1[i ] = max(dp1[i-1], nums[i] + dp1[i-2]);
            cout << i << " " << dp1[i] << '\n';
        }        
        dp2[0] = 0;
        for (int i = 1; i < n ; i++) {
            dp2[i] = max(dp2[i-1] , nums[i] + ((i-2 >= 0) ? dp2[i-2] : 0));
            cout << i << " " << dp2[i] << '\n';

        }
        return max(dp2[n-1],dp1[n-2]);
        
    }
};

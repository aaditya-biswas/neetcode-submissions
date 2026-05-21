class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l = 0 ; 
        int r = nums.size() - 1;
        int n = nums.size();
        vector<int > forward_freq(n);
        vector<int> backward_freq(n);
        vector<vector<int>> res;
        sort(nums.begin( ) , nums.end());
        forward_freq[n - 1] = 1;
        backward_freq[0] =1;
        for (int i= n -2  ;i > -1 ; i-- ) {
            if (nums[i] == nums[i + 1]) forward_freq[i] = forward_freq[i+1] + 1;
            else forward_freq[i ] =1;
        }
        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] == nums[i - 1]) backward_freq[i] = backward_freq[i-1] + 1;
            else backward_freq[i ] =1;
        }
        while ( l < r) {
            int m = l + 1;
            int r_bound = r;
            while (m  <  r_bound) {
                if (nums[l] + nums[m] + nums[r_bound] == 0)  {
                    res.push_back( { nums[l] , nums[m],  nums[r_bound] });
                    m += forward_freq[m];
                    r_bound -= backward_freq[r_bound];
                }
                else if (nums[l] + nums[m] + nums[r_bound] < 0 ) m += forward_freq[m];
                else r_bound -= backward_freq[r_bound];
            }
            l+= forward_freq[l];
        }
        return res;
    }
};

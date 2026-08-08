#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int farthest_ind = 0;
        for (int i = 0 ; i < n; i++  ) {
            if (farthest_ind < i) return false;
            farthest_ind = max(i + nums[i],farthest_ind); 
        }        
        return farthest_ind >= n-1;
    }
};

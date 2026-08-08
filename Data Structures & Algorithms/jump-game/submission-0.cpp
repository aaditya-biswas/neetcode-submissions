class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int best_ind = 0;
        for (int i = 0 ; i <= min(best_ind, n -1 ) ; i++  ) {
            best_ind = max(i + nums[i],best_ind); 
        }        
        return best_ind >= n-1;
    }
};

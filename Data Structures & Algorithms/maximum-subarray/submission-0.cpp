class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // max
        int best_score = nums[0];
        int prev = nums[0];
        for (int i  = 1; i < nums.size() ; i++ ) {
            prev = max(prev + nums[i], nums[i]);
            best_score = max(best_score , prev);
        }
        return best_score;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Solving in O(n)
        // Trick : BReak down the problem to solving for before the number and after the number
        int n  = nums.size();
        vector<int > res(n , 1);
        int prefix = 1;
        for (int i = 1 ; i < n;i++) {
            prefix *= nums[i-1];
            res[i] *= prefix;
        }
        int postfix = 1;
        for (int i = n- 2 ; i >= 0;i--) {
            postfix *= nums[i+1];
            res[i] *= postfix;
        }
        return res;
    }
};

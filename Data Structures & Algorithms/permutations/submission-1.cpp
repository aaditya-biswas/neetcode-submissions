class Solution {
public:
    void permuteAll(vector<int> & permutation, vector<vector<int>> & res, vector<int> & nums,int ind){
        if (ind == nums.size()){
             res.push_back(permutation);
            return;
        }
        for (int i = 0 ; i < permutation.size() ; i++) {
            if (permutation[i] == -11) {
                permutation[i] = nums[ind];
                permuteAll(permutation , res, nums, ind +1 );
                permutation[i] = -11;
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // 
        vector<int> permutation(nums.size() ,- 11);
        vector<vector<int>> res;
        permuteAll(permutation, res, nums, 0);
        return res;
    }
};

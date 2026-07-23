class Solution {
public:
    void calc(vector<vector<int>> & res,vector<int> & temp, vector<int > & nums , int target, int ind ) {
        if (ind < 0) return;
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        // Not take;
        calc(res,temp,nums, target , ind - 1);
        // Take 
        if (target >= nums[ind]) {
            temp.push_back(nums[ind]);
            calc(res, temp ,nums, target - nums[ind], ind );
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int > temp;
        int ind = nums.size() - 1;
        calc(res, temp , nums,  target , ind );
        return res;
    }
};

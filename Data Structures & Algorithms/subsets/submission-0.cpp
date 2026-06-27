class Solution {
public:
    void calc(vector<vector<int>> & res, int ind , vector<int> & nums,vector<int> & temp) {
        if (ind == -1) {
            res.push_back(temp);
            return;
        } 
        // Not take 
        calc(res, ind - 1, nums , temp);
        // Take
        temp.push_back(nums[ind]); 
        calc(res, ind - 1, nums ,temp);
        temp.pop_back();
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        calc(res,n-1, nums,temp);
        return res;
    }
};

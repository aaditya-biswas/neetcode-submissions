class Solution {
public:
    void calc(vector<vector<int>> & res,vector<int> & temp, vector<int > & nums , int target, int ind, unordered_map<int,int> & hashMp ) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (ind < 0) return;

        // Not take;
        calc(res,temp,nums, target , ind - 1,hashMp);
        // Take 
        
        for (int i = 1 ; i <=  hashMp[nums[ind]]; i++) {
            if (i * nums[ind] > target) break;
            temp.push_back(nums[ind]);
            calc(res,temp , nums,  target - i * nums[ind],ind - 1, hashMp);
        }
        for (int i = 1; i <= hashMp[nums[ind]] ; i++)  {
            if (i * nums[ind] <= target)
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int > temp;
        int ind = nums.size() - 1;
        // Make into a hash set
        unordered_map<int,int> hashMp;
        vector<int> filtered;
        for (int i = 0 ; i < nums.size()  ; i ++ ) {
            if (!hashMp.contains(nums[i])) {
                filtered.push_back(nums[i]);
            }
            hashMp[nums[i]]++;
            
        }
        calc(res, temp , filtered,  target , filtered.size() - 1, hashMp );
        return res;
    }
};

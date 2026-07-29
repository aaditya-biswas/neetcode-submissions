class Solution {
public:
    void calculate(int ind ,vector<int> & nums, unordered_map<int ,int > & freqMap ,vector<int> & temp, vector<vector<int>> & res  ) {
        if (ind >= nums.size()){
            res.push_back(temp);
            return;
        }
        for (int i = 0; i <= freqMap[nums[ind]]; i++ ) {
            calculate(ind + freqMap[nums[ind]],nums, freqMap,temp, res);
            temp.push_back(nums[ind]);
        }
        for (int i = 0 ; i <= freqMap[nums[ind]] ; i++) {
            temp.pop_back();
        }
        return;
    }
    vector <vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array 
        sort(nums.begin(),nums.end());
        // Skip using the frequency 
        unordered_map<int, int > freqMap;
        for (auto &m : nums) {
            freqMap[m]++;
        }
        vector<vector<int>> res;
        vector<int> temp;
        calculate(0,nums,freqMap,temp,res);
        return res;
    }
};

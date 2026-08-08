class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Longest increasing subsequence
        vector<int> st;

        for (int i = 0; i < nums.size() ; ++i) {
            auto it = lower_bound(st.begin() , st.end() , nums[i]);
            if (it == st.end()) st.push_back(nums[i]);
            else *it = nums[i];         
        }

        return st.size();
    }
};

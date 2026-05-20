class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<pair<int,int>> freq;

        for (int i = 0 ; i < nums.size();  i++) {
            mp[nums[i]]++;
        }
        for (auto m : mp) {
            freq.push_back({m.second , m.first});
        }
        sort(freq.begin(),freq.end());
        vector<int > res;
        for ( int i = 0; i < k; i++) {
            res.push_back(freq[freq.size()-1-i].second);
        }
        return res;
        
    }
};

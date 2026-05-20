class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for (auto m  : nums) {
            
            if (mp.find(m ) != mp.end()) return true;
            mp.insert(m);
        }     
        return  false;
    }
};
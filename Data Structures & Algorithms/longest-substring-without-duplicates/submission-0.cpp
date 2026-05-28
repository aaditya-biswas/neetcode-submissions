class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // Find the lendth ofthe longest substring without duplicate characters
        // Step 1. Define the optimal substring boundary left  to be l and right to be r
        // Step 2. If arr[l] == arr[r]
        if (s.size() == 0) return 0;
        int maxLen = 1;
        int n = s.size();
        int l = 0;
        int r = 0;
        unordered_set<char> hashMap;
        while (l < n && r < n) {
            while (hashMap.find(s[r]) != hashMap.end()) {
                hashMap.erase(s[l]);
                l++;
            } 
            hashMap.insert(s[r]);
            r++;
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Make a unordered_map 
        // Step 2 : Insert all the elements in the unorderd_map
        // Step 3 : If already inserted increment the next one and insert it
        // Step 4 : Track the maximum accross the unordered_map elements
        unordered_map<int,int> hashMap;
        int maxVal = 0;
        for (int i = 0 ; i < nums.size();  i++) {
            hashMap[nums[i]] = 1;
        }
        for (int i = 0 ; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                int len = hashMap[nums[i]];
                int val = nums[i] - 1;
                while (hashMap.find(val ) != hashMap.end()) {
                    len += hashMap[val];
                    hashMap.erase(val);
                    val--;
                }
                hashMap[nums[i]] = len; 
                maxVal = max(maxVal , len);
            }
        }
        return maxVal;
    }
};

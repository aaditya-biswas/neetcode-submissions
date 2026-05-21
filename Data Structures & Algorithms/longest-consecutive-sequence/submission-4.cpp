class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int length=0, longest=0;
        for(int i=0;i<nums.size();i++)
        {
            if(seen.find(nums[i]-1)==seen.end())
            {
                length=0;
                int element=nums[i];
                while(seen.find(element)!=seen.end())
                {
                    length++;
                    element++;
                }
                longest=max(length, longest);
            }
        }
        return longest;
    }
};

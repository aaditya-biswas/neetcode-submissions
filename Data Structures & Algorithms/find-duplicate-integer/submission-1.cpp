class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // It can be proved that we will remain swapping until we alternate the swapping between the repeated numbers
        int r = 0;
        int n = nums.size();
        while (r < n ) {
            if (nums[r] == r  + 1) r++;
            else {
                // swap 
                if (nums[r] == nums[nums[r]-1]) return nums[r];
                swap(nums[r],nums[nums[r] - 1]);
            }
        }
        return -1;
    }
};

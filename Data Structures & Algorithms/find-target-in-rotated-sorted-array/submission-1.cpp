class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        // Logic : At any point of time one half is sorted 
        // So search in that sorted half 
        // If it exists in that sorted half then choose that one 
        // Else shift it 
        while ( l  <= r) {
            int mid = l + (r - l ) /2 ;
            if (nums[mid] == target ) {
                return mid;
            }
            else if (nums[l] <= nums[mid]) {
                // Left half sorted 
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if (nums[mid] < nums[r] ) {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;  
    }
};

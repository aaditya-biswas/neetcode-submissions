class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size();i++) {
            x ^= nums[i];
        }
        for (int i = 0 ; i <= n;i++) {
            x ^= i;
        }
        return x;
    }
};

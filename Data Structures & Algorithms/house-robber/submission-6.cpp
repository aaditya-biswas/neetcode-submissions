#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto __boost_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int rob(vector<int>& nums) {
        // Max
        if (nums.size() == 1) return nums[0];
        int n = nums.size() ;
        int prev2 = nums[0];
        int prev1 = max(nums[1],nums[0]);
        for (int i = 2; i < n ; i++) {
            int temp = prev1;
            prev1 = max(prev1 , nums[i] + prev2 );
            prev2 = temp;
        }
        return prev1;
    }
};

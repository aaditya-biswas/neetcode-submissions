#pragma GCC optimize("O3,unroll-loops,omit-frame-pointer,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto __boost_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rob(const vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];

        // Raw restricted pointer avoids vector indexing overhead and signals no memory aliasing
        const int* __restrict ptr = nums.data();

        int prev2 = ptr[0];
        int prev1 = std::max(ptr[0], ptr[1]);

        int i = 2;
        // Manual 2x unrolling: eliminates temporary variable swaps and halves loop control jumps
        for (; i + 1 < n; i += 2) {
            prev2 = std::max(prev1, ptr[i] + prev2);      // Target for index i
            prev1 = std::max(prev2, ptr[i + 1] + prev1);  // Target for index i + 1
        }

        // Clean up remaining element for odd array lengths
        if (i < n) {
            int temp = prev1;
            prev1 = std::max(prev1, ptr[i] + prev2);
            prev2 = temp;
        }

        return prev1;
    }
};
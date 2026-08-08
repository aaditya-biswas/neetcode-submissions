#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto __boost_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // vector<char> is faster and cleaner for cache locality than vector<int>
        vector<char> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            // Prune unreachable indices immediately
            if (!dp[i]) continue;

            for (const string& word : wordDict) {
                int len = word.size();
                if (i + len <= n && !dp[i + len]) {
                    // s.compare uses hardware AVX2 vector instructions
                    if (s.compare(i, len, word) == 0) {
                        dp[i + len] = 1;
                    }
                }
            }

            // Early termination as soon as the last index is reachable
            if (dp[n]) return true;
        }

        return dp[n];
    }
};
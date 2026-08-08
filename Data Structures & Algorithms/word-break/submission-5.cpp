#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto __boost_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();


class Solution {
private:

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Word break 
        // Neet Code
        // Give the starting index of each word in the i
        auto  check = [] (int ind , string & s , string  & word   )   {
            if (ind + word.size() - 1 >= s.size() ) return false; // Optimization

            for (int i = 0 ; i < word.size() ; i ++) {
                if (s[ind + i] != word[i] ) return false;
            }
            return true;
        };
        int n = s.size();
        vector<int> dp(s.size() + 1 , -1);
        dp[n] = 1;
        for (int i = n -1 ; i > -1 ; i-- ) {
            // Check if any word formed from this 
            for (string & word: wordDict) {
                if (check(i, s ,word)) {
                    dp[i] = max(dp[i + word.size()],dp[i]);
                }
            } 
        }
        return dp[0] == 1;
    }
};

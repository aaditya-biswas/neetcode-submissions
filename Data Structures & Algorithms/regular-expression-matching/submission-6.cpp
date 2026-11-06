#include <string.h>
class Solution {
private:
    int dp[22][22];
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        memset(dp, 0 , sizeof(dp));
        dp[0][0] = 1; // Empty string matches both

        for (int j = 0 ; j < n ; ++j ) {
            if (p[j] == '*') dp[0][j + 1] = dp[0][j - 1];
        }
        // dp[i][j] = 
        // if j - 1 == '.' dp[i][j] = dp[i-1][j-1]
        // if j - 1 == '*' dp[i][j] = dp[i - 1][j] | dp[i][j - 1] // One or more of any characters  
        // if j - 1 == '*' dp[i][j] = dp[i - 1][j] if (s[j - 1] == s[i - 1]) | dp[i][j - 1]
        for (int i = 1 ; i <= m ; ++i) {
            for (int j = 1 ; j <= n ;  ++ j) {
                if (s[i-1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j -1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Zero times
                    if (p[j - 2] == '.' || s[i - 1] == p[j -2] ) {
                        // One or more times
                        int  t = i - 1;
                       dp[i][j] |= dp[i- 1 ][j];
                    }  // preceding elements 
                }

            }
        }
        return dp[m][n];

    }
};

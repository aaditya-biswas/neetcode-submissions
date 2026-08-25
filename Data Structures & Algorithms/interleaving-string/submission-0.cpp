#include <bits/stdc++.h>
class Solution {
private:
    int m, n , p;
    string s1, s2, s3;
    int dp[101][101][201];
    bool dfs(int l1 , int l2 , int l3) {
        if (l1 == m && l2 == n ) return true;
        if (dp[l1][l2][l3] != -1) return dp[l1][l2][l3];
        if (l1 == m ) {
            if (s2[l2] != s3[l3]) return false;
            return dfs(l1,l2 + 1,l3 + 1);
        }
        else if (l2 == n) {
            if (s1[l1] != s3[l3]) return false;
            return dfs(l1 + 1,l2,l3 + 1);
        }

        // Check both
        bool res = false;
        if (s1[l1] == s3[l3]) {
            res = res || dfs(l1+ 1, l2 , l3 + 1);
        }
        if (s2[l2] == s3[l3]) {
            res = res || dfs(l1, l2 + 1, l3 + 1);
        }
        return dp[l1][l2][l3] = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();
        p = s3.size();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memset(dp, -1, sizeof(dp));
        if (m + n != p) return false;
        return dfs(0,0,0);
    }
};

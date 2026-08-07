class Solution {
public:
    int countSubstrings(string s) {
        int max_len = 1;
       int n = s.size(); 
       vector<vector<int>> dp(n, vector<int> (n, 0));
        int count = 0;
       for (int i = 0 ; i < n ; i++ ) {
            dp[i][i] = 1;
            count++;
       }
       for (int i = 0 ; i < n- 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;

                count++;
            }
       }
       for (int i = n - 3 ; i > -1; i-- ){
            for (int j = i + 2; j < n ; j++) {
                dp[i][j] = (((s[i] == s[j]) && dp[i+1][j -1 ]) ? 1 : 0);
                if (dp[i][j]) count++;
            }
       }
       return count;
    }
};

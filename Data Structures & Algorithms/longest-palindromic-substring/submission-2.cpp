class Solution {
public:
    string longestPalindrome(string s) {
       int max_len = 1;
       int n = s.size(); 
       vector<vector<int>> dp(n, vector<int> (n, 0));
        int max_val = 1;
        pair<int,int> pos = {0,0};
       for (int i = 0 ; i < n ; i++ ) {
            dp[i][i] = 1;
       }
       for (int i = 0 ; i < n- 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 2;
                max_val = 2;
                pos = {i , i +1};
            }
       }
       for (int i = n - 3 ; i > -1; i-- ){
            for (int j = i + 2; j < n ; j++) {
                dp[i][j] = (((s[i] == s[j]) && dp[i+1][j -1 ]) ? dp[i+1][j-1] + 2 : 0);
                if (max_val < dp[i][j]) {
                    max_val = dp[i][j];
                    pos = {i , j};
                }
            }
       }
       return s.substr(pos.first , pos.second - pos.first + 1 );
        
    }
};

class Solution {
public:
    int numDecodings(string s) {
        // Num decodings 
        // We need to traverse from the reverse 
        // The recurrence if W[i , i +1] + dp[i + 2 ] and W[i ] + dp[i +1 ]
        int n = s.size();
        if (s.size() == 1) return s != "0"; 
        vector<int> dp(n + 1, 0);
        // Base cases
        // Empty 
        dp[n ] = 1;
        dp[n-1 ] = s[n-1] != '0';
        for (int i = n - 2; i >  -1; i--  ) {
            int val = 0;
            if (s[i] == '0') dp[i] = 0;
            else if (s[i] == '1' || s[i] == '2') {
                if (s[i] == '1') dp[i] = dp[i+1] + dp[i+2];
                else if (s[i] == '2' && (s[i+1] >= '0' && s[i +1 ] <=  '6')) dp[i] = dp[i+1] + dp[i +2 ];
                else dp[i] = dp[i+1];
            }
            else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};

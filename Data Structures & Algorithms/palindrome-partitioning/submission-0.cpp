class Solution {
private:
    void calculate(int  ind , vector<vector<int>> &dp ,string word ,vector<string> & temp, vector<vector<string >> & res) {
        if (ind >= word.size()) {
            res.push_back(temp);
            return;
        }
        for (int len = 1 ; ind + len -1 < word.size(); len++ ) {
            if (dp[ind][ind + len - 1]) {
                temp.push_back(word.substr(ind, len));
                calculate(ind + len,dp , word ,temp , res);
                temp.pop_back();
            }
        }
        return;
    }


public:
    
    
    vector<vector<string>> partition(string s) {
        // Can be done via a window of size 1, 2,3 ..
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n,0));
        
        for (int len = 1; len <= n ; len++) {
            for (int j = 0; j + len - 1 < n; j++) {
                if (len == 1) {
                    dp[j][j+ len - 1] = 1;
                    continue;
                }
                else if (len == 2) {
                    dp[j][j + len - 1] = (s[j] == s[j + 1]);
                    continue;
                }
                dp[j][j + len - 1] = dp[j + 1][j + len - 2] && (s[j]  == s[j + len-1 ]);
            }
        }
        // Now find all valid partitions 
        vector<vector<string > > res;
        vector<string > temp;
        calculate(0 , dp , s, temp ,res);
        return res;

    
    }
    
};

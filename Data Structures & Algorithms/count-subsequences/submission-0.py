# num distinct subsequences 
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        # number of distinct subsequences 
        if len(s) < len(t): return 0
        m : int = len(s)
        n : int = len(t)

        # number of distinct subsequences upto character i of s which are equal to upto character j of t
        #  dp[i][j] = (isEqual ? 1+ dp[i-1][j-1] : dp[i -1 ][j] + dp[i][j - 1] - dp[i-1][j-1]) # PIE
        
        dp : list[list[int]] = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(0,m + 1):
            dp[i][0] = 1
        
        for i in range(m):
            for j in range(n):
                isEqual : bool = s[i] == t[j]
                if isEqual:
                    dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1]
                else:
                    dp[i+1][j+1] = dp[i][j +1] 
        

        return dp[m][n]
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # askn 02
        m : int = len(word1)
        n : int = len(word2)
        # Dp of length m and n
        # Insertion can be visualized as deletion of opposite sequence

        dp : list[list[int]] = [[1e9 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for i in range(n + 1):
            dp[0][i] = i 
        for i in range(m):
            for j in range(n):
                isEqual = 0 if word1[i] == word2[j] else 1
                dp[i+1][j+1] = min(isEqual + dp[i][j], 1+ dp[i][j + 1],  1+ dp[i+ 1][j])
        return dp[m][n]
        # dp[i][j] = min(1 + dp[i-1][j-1] , dp[i-1][j], dp[j][])

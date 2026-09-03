class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int m;
    int n;
    int dfs(int i , int j , vector<vector<int>>  & mat,vector<vector<int>> & vis) {
        vis[i][j] = 1;
        int max_inc= 0;
        for (int k = 0; k < 4; ++k) {
            int rw = i + dr[k];
            int cl = j + dc[k];
            if (rw < m && cl < n && rw > -1 && cl > -1 && mat[rw][cl] > mat[i][j]) {
                if (!vis[rw][cl]) {
                    max_inc = max(max_inc, dfs(rw,cl, mat,vis));
                }
                else {
                    max_inc = max(max_inc, vis[rw][cl]);
                }
            }
        }
        return vis[i][j] = max_inc + 1;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Blood hound 
        // Longest strictly increasing path
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> vis(m , vector<int> (n, 0));
        int max_val =  INT_MAX;
        int ans = 0;
        for (int i  = 0; i < m; ++i) {
            for (int j = 0; j < n ; ++j) {
                if (!vis[i][j]) {
                    ans = max(ans, dfs(i,j,matrix,vis));
                }
            }
        }
        return ans;
    }
};

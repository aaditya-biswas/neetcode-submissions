class Solution {
public:
    int m , n ;
    void move(vector<vector<int>> & vis ,vector<vector<int>> & mat, vector<int> & res ,int i , int j ) {
        if (i >= m || i < 0 || j >= n || j < 0 ) return;
        if (vis[i][j]) return;
        vis[i][j] = 1;
        res.push_back(mat[i][j]);
        while (j + 1 < n && !vis[i][j+1]) {
            j++;
            vis[i][j] = 1; 
            res.push_back(mat[i][j]);
        } 
        while (i +1 < m && !vis[i+1][j]) {
            i++;
            vis[i][j] = 1; 
            res.push_back(mat[i][j]);
        } 
    
        while (j -1 > -1 && !vis[i][j-1] ) {
            j--;
            vis[i][j] = 1; 
            res.push_back(mat[i][j]);
        }
        while (i - 1 > -1 && !vis[i-1][j]){
            i--;
            vis[i][j] = 1; 
            res.push_back(mat[i][j]);
        }
        move(vis,mat,res,i  , j+ 1);
        return;

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      // Spiral Matrix
        m = matrix.size();
        n = matrix[0].size(); 
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int> res;
        move(vis, matrix , res, 0 , 0);
        return res;
    }
};
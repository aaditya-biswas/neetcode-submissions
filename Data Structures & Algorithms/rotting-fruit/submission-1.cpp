class Solution {
public:
    using pt = pair<int,int>;
    void bfs(queue<pt> & q,vector<vector<int>> & grid, vector<vector<int>> & vis,vector<vector<int>> & dist){
        int m = grid.size();
        int n = grid[0].size();
        int dr[]=  {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while (!q.empty()){
            auto [x,y ] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = dr[i] + x;
                int col = dc[i] + y;
                if (row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1 && !vis[row][col]) {
                    vis[row][col] = 1;
                    dist[row][col] = dist[x][y]  +1;

                    q.push({row,col});
                    
                }
            }
        }
    }  
    int orangesRotting(vector<vector<int>>& grid) {
        // Multi Source BFS
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pt> q;
        for (int  i = 0; i < m; i++) {
            for (int j = 0; j < n;j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        // Multi Source BFS
        bfs(q,grid,vis,dist);

        // Now search for the maximum banana dist
        int max_min = 0;
        for (int i = 0 ; i < m; i++ ){
            for (int j = 0; j < n ; j++) {
                if (grid[i][j] == 1 ) {
                    max_min = max(max_min,dist[i][j]);
                }
            }
        }
        if (max_min == INT_MAX) return -1;
        return max_min;
    }
};

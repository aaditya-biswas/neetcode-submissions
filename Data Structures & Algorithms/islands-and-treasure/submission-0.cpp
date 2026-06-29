class Solution {
public:
    int dr[4 ] = { -1 , 0, 1, 0};
    int dc[4] = {0,-1,0,1};
    void bfs(vector<vector<int>> & grid, queue<pair<int,int>> & q) {
        int dist = 1;
        int m = grid.size();
        int n= grid[0].size();
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size;i++) {
                auto node = q.front();
                q.pop();
                for (int k = 0; k < 4;k++) {
                    int rw =node.first + dr[k];
                    int cl = node.second + dc[k];
                    if (rw < m && cl < n && rw >= 0 && cl >= 0 && grid[rw][cl] == INT_MAX) {
                        grid[rw][cl] = dist;
                        q.push({rw,cl});
                    }
                }
            }
            dist++;
        }
        return;
    }
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Multi Source BFS
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }
        bfs(grid,q);
        return;
    }
};

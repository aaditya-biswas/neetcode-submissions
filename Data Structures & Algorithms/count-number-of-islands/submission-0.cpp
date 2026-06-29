class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int dr[] = {-1,0,1,0};
        int dc[] =  {0,-1,0,1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j ] = 1;
                    while(!q.empty()) {
                        auto node= q.front();
                        q.pop();
                        for (int k = 0 ; k < 4; k++) {
                            int row =  node.first  + dr[k];
                            int col = node.second + dc[k];
                            if (row < m && col < n && row >= 0 && col >= 0 && grid[row][col] == '1'  && !vis[row][col]) {
                                vis[row][col] = 1;
                                q.push({row,col});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

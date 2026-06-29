class Solution {
public:
    int dr[4] = {-1, 0 , 1 , 0};
    int dc[4] = {0,-1,0,1};


    int calcSize(int i , int j , vector<vector<int>> & vis , vector<vector<int>> & grid) {
        vis[i][j] = 1;
        int size = 1;
        for (int k = 0; k < 4 ; k++) {
            int rw = i + dr[k];
            int cl = j + dc[k];
            if (rw < grid.size() && cl < grid[0].size() && rw >= 0 && cl >= 0 && grid[rw][cl] == 1 && !vis[rw][cl])
            size  += calcSize(rw,cl,vis,grid);         

        }
        return size;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxSize = 0;
        vector<vector<int>> vis(m,vector<int> (n,0));


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !vis[i][j]) maxSize = max(maxSize, calcSize(i,j,vis,grid));
            }
        }

        return maxSize;
    }
};

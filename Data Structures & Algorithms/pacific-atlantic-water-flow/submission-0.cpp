class Solution {
public:
    using pt = pair<int,int>;
    void bfs(vector<vector<int>>  & heights, queue<pt> & q, vector<vector<int>> & ocean) {
        int m = heights.size();
        int n = heights[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for (int i = 0 ; i < 4 ;i++) {
                int rw = x + dr[i];
                int cl = y + dc[i];
                if (rw >= 0 && cl >= 0 && rw < m && cl < n && !ocean[rw][cl] && heights[rw][cl] >= heights[x][y] ) {
                    ocean[rw][cl] = 1;
                    q.push({rw,cl});

                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Multi source bfs for both pacific and atlantic 
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));

        queue<pt> q;
        // Pacific Ocean
        for (int i = 0; i < n; i++) {
            pacific[0][i] = 1;
            q.push({0,i});
        }
        for (int i = 1; i < m;i++ ) {
            pacific[i][0] = 1;
            q.push({i,0});
        } 
        bfs(heights,q,pacific);
        // Atlantic ocean
        for (int i = 0; i < n; i++) {
            atlantic[m-1][i] =  1;
            q.push({m-1,i});
        }
        for (int i = 0 ; i < m - 1; i++) {
            atlantic[i][n-1] = 1;
            q.push({i,n-1});
        }
        bfs(heights ,q ,atlantic);
        vector<vector<int>> res;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (atlantic[i][j] && pacific[i][j]) res.push_back({i,j});
            }
        }
        return res;

    }
};

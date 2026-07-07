class Solution {
public:
    using pt = pair<int,int>;
    void bfs(vector<vector<char>> & board, queue<pt> & q,vector<vector<int>> & vis) {
        int m = board.size();
        int n = board[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while (!q.empty()) {    
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0 ; i < 4 ; i++) {
                int rw = x + dr[i];
                int cl = y + dc[i];
                if (rw >= 0 && cl >= 0 && rw < m && cl < n && board[rw][cl] == 'O' && !vis[rw][cl] ) {
                    vis[rw][cl] = 1;
                    q.push({rw,cl}); 
                }
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        // Multi source bfs
        int m = board.size();
        int n = board[0].size();
        queue<pt> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for (int i = 0 ; i < m ; i++) {
            if (board[i][0] == 'O') {
                vis[i][0] = 1;
                q.push({i,0});
            }
            if (board[i][n-1] == 'O') {
                vis[i][n-1] = 1;
                q.push({i,n-1});
            }
        }
        for (int i = 1; i < n-1;i++) {
            if (board[0][i] == 'O') {
                vis[0][i] = 1;
                q.push({0,i});
            }
            if (board[m-1][i] == 'O'){
                vis[m-1][i] = 1;
                q.push({m-1,i});
            }
            
        }
        // Perform BFS
        bfs(board,q,vis);
        // After that count the occurences of O
        for (int i = 0 ; i < m ; i ++) {
            for (int j = 0 ; j < n ; j ++ ) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};

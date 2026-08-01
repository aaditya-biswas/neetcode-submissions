class Solution {
public:
    int dr[4] = {- 1, 0 , 1, 0};
    int dc[4] = {0 , - 1, 0 , 1};
    bool wsearch(int i , int j, int ind,string word,vector<vector<char>> & board , vector<vector<int>> vis) {
        if (ind >= word.size()-1) {
            return true;
        }
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int rw = i + dr[k];
            int cl = j + dc[k];
            if (rw < board.size() && cl < board[0].size()  && rw >= 0 && cl >= 0 && !vis[rw][cl] && board[rw][cl] == word[ind + 1])         if(wsearch(rw,cl, ind +1 , word,board, vis )) return true;
        }
        vis[i][j] = 0;
        return false;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        // Pick the starting index of the word;
        int m = board.size(); 
        int n = board[0].size();
        vector<vector<int>>  vis(m,vector<int> (n,0));
        for (int i = 0 ; i < m ;  i++ )  {
            for (int j = 0 ; j < n ; j++) {
                if (board[i][j] == word[0] &&  wsearch(i,j,0,word,board,vis)) return true;
            }
        }
        return false;
    }
};

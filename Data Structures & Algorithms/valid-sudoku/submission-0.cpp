class Solution {

public:
    bool checkBoxes(vector<vector<char >> & board) {
        int dr[] = {-1,0,1};
        int dc[] = {-1,0,1};
        int center_x[] = {1, 4, 7};
        int center_y[] = {1, 4, 7};
        for (int i = 0 ; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> hashMap;
                for (int k = 0 ; k < 3 ; k++) {
                    for (int l = 0 ; l < 3 ; l++) {
                        if (hashMap.find(board[center_x[i] + dr[k]][center_y[j] + dc[l]]) != hashMap.end()) return false;
                        if (board[center_x[i] + dr[k]][center_y[j] + dc[l]] >= '0' && board[center_x[i] + dr[k]][center_y[j] + dc[l]] <= '9')hashMap.insert(board[center_x[i] + dr[k]][center_y[j] + dc[l]]);
                    }
                }
            }
        }
        return true;
    } 
    bool checkRows(vector<vector<char>> & board) {
        for (int i = 0 ; i < 9; i++) {
            unordered_set<char> hashMap;
            for (int j = 0 ; j < 9;j++) {
                if (hashMap.find(board[i][j]) != hashMap.end()) return false;
                if (board[i][j] >= '0' && board[i][j] <= '9')hashMap.insert(board[i][j]);
            }   
        }
        return true;
    }

    bool checkColumns(vector<vector<char>> & board) {
        for (int i = 0 ; i < 9; i++) {
            unordered_set<char> hashMap;
            for (int j = 0 ; j < 9;j++) {
                if (hashMap.find(board[j][i]) != hashMap.end()) return false;
                if (board[j][i] >= '0' && board[j][i] <= '9')hashMap.insert(board[j][i]);
            }   
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return (checkBoxes(board) && checkRows(board) && checkColumns(board));
    }
};

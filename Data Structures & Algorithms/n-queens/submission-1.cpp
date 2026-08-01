class Solution {
private:
    void clearPos(int i , int j , vector<vector<int>> & filledBoard) {
         // Fill down and left down diagonal and right diagonal
        int x,y;
        filledBoard[i][j] = 0;
        x = i , y=  j;
        while (++x < filledBoard.size() && ++y < filledBoard.size() ){
            filledBoard[x][y]--;
        }
        x = i , y= j;
        while (++x < filledBoard.size() && --y > -1) {
            filledBoard[x][y]--;
        }
        x = i, y= j;
        while (++x < filledBoard.size()) {
            filledBoard[x][y]--;
        }
        return;
    }
    void fillPos(int i ,int j, vector<vector<int> > & filledBoard){
        // Fill down and left down diagonal and right diagonal
        int x,y;
        filledBoard[i][j] = 1;
        x = i , y=  j;
        while (++x < filledBoard.size() && ++y < filledBoard.size() ){
            filledBoard[x][y]++;
        }
        x = i , y= j;
        while (++x < filledBoard.size() && --y > -1) {
            filledBoard[x][y]++;
        }
        x = i, y= j;
        while (++x < filledBoard.size()) {
            filledBoard[x][y]++;
        }
        return;
    }
    void calculateBoardConfigs(int rw, vector<vector<int>> & filledBoard , vector<string >  & temp, vector<vector<string >> & res ) {
        int n = filledBoard.size();
        if (rw >= n) {
            res.push_back(temp);
            return;
        }
        string boardRow(n,'.');
        for (int j = 0; j < n ; j++) {
            if (!filledBoard[rw][j]) {
                fillPos(rw ,j,filledBoard);
                boardRow[j] = 'Q';
                temp.push_back(boardRow);
                calculateBoardConfigs(rw + 1, filledBoard, temp , res);
                temp.pop_back();
                boardRow[j] = '.';
                clearPos(rw,j,filledBoard);
            }
        }
        return;
    }
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> filledBoard(n,vector<int>(n,0));
        vector<string> temp;
        vector<vector<string>> res;
        calculateBoardConfigs(0 , filledBoard, temp ,res);
        return res;

    }
};

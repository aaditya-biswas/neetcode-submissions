class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      // Rotating an image 
      // Picture a rod moving 
      // There are 2 * m  - 2 squares that need to be replaced ;
      int m = matrix.size();
      for (int i = m ; i > 1; i -= 2) {
        // GOt the size of the side 
        int start = (m - i ) / 2;
        int end = (m  + i  - 2) / 2;
        int length = i;

        // Swap the first row and the last column
        // Swap the corners as  they are giving trouble 
        swap(matrix[start][start], matrix[start][end]);
        swap(matrix[end][start], matrix[end][end]);
        swap(matrix[start][start],matrix[end][end]);
        int y = start + 1;

        for (int k = start + 1; k <= end - 1; ++k) {
            swap(matrix[start][k], matrix[y][end]);
            y++;
        }
        y = end - 1;
        for (int k = start + 1; k<= end -1; ++k) {
            swap(matrix[start][k], matrix[y][start]);
            y--;
        }
        y = start + 1;
        for (int k = start + 1; k <= end - 1; ++k) {
            swap(matrix[y][start], matrix[end][k]);
            y++;
        }

      }
         
    }
};

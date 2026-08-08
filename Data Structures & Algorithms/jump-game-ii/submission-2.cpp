class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1 ) return 0;
        int n = nums.size();
        int r = 0;
        int moves = 0;
        int allowed_ind = r + nums[r];
        while (r < n ) {
            moves++;
            int farthest_ind = r;
            cout << allowed_ind << endl;
            for (; r <= min(n-1, allowed_ind)  ; r++) {
                farthest_ind = max(farthest_ind , r + nums[r]);
            }
            cout << r << endl;
            allowed_ind = farthest_ind;
        }
        return moves ;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int  l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;
        while (l < r ) {
            if (heights[l] < heights[r]) {
                maxArea = max(maxArea,(  r  -l  ) * heights[l]);
                l++;
            }
            else if (heights[r ]  < heights[l] ) {
                maxArea = max(maxArea, ( r - l) * heights[r]);
                r--;
            }
            else {
                maxArea = max(maxArea, ( r - l) * heights[r]);
                r--;
                l++;
            }
        } 
        return maxArea;
    }
};
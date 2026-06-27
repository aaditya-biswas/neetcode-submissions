class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n,0);
        vector<int> rightSmaller(n,0);
        stack<int > stk;
        for (int i = 0; i < n;i++) {
            if (stk.empty() || heights[stk.top()] <= heights[i]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && heights[stk.top()] > heights[i]) {
                    rightSmaller[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);

            }
        }
        while (!stk.empty()) {
            rightSmaller[stk.top()] = n;
            stk.pop();
        }
        for (int i = n-1; i > -1;i--) {
            if (stk.empty() || heights[stk.top()] <= heights[i]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && heights[stk.top()] > heights[i]) {
                    leftSmaller[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);

            }
        }
        while (!stk.empty()) {
            leftSmaller[stk.top()] = -1;
            stk.pop();
        }
        int mx = 0;
        for (int i = 0;  i < n ; i++) {
            mx = max((rightSmaller[i] - leftSmaller[i] - 1)*heights[i],mx);
        }
        return mx;
    }
};

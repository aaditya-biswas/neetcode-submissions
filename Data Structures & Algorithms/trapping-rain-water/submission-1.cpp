class Solution {
public:
    int trap(vector<int>& height) {
        // Step 1. Make a monotonic stack with the next greater element
        // Step 2. Whenever we have a element greater than the stk.top() we pop until we reach a element that is greater than the current height
        // Step 3. In the pop method there is a niche condition the condition is that to add the area we use
        // area += ( i - stk.top()) * (height[stk.top()])
        // Step 4. After that we push the current element and return the maximum Area
        int n  = height.size();
        stack<int> stk;
        int area = 0;
        for (int i = 0; i < n ; i++) {
            if (stk.empty() || height[i] < height[stk.top()]) {
                stk.push(i);
            }
            else {
                int last_height = 0;
                while (!stk.empty() && height[i] >= height[stk.top()] ) {
                    area += ( i - stk.top() -1 ) * (height[stk.top()] - last_height);
                    last_height = height[stk.top()];
                    stk.pop();
                }
                if (!stk.empty()) area +=  (i - stk.top() -1 ) * (height[i] - last_height);
                stk.push(i);
            }
        } 
        return area;
    }
};

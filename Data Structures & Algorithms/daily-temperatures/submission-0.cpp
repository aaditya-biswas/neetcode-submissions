class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> result(temperatures.size());
        for (int i = 0 ; i < temperatures.size();i++) {
            if (stk.empty() || temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
            }
            else {
                while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                    result[stk.top()] = i -stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            result[stk.top()] = 0;
            stk.pop();
        }
        return result;
        
    }
};

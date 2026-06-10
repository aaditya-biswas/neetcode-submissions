#include <string>

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> q;
        unordered_map<string, int> mp = { {"+", 1}, {"-", 1}, {"*", 1}, {"/", 1} }; 
        int res = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (mp[tokens[i]]) {
                int val1 = 0, val2 = 0;
                
                val1 = stoi(q.top()); q.pop();
                val2 = stoi(q.top());
                q.pop();
                if (tokens[i] == "+") {
                    q.push(to_string(val1 + val2) );
                }
                else if (tokens[i] == "-") q.push(to_string (val2 - val1) );
                else if (tokens[i] == "*") q.push(to_string ( val1 * val2) );
                else  q.push(to_string(val2  / val1) );
            }
            else q.push(tokens[i]);
        }
        return stoi(q.top());
    }
};

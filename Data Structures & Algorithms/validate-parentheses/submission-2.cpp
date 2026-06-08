class Solution {
public:
    bool isValid(string s) {
        // Follow a simple rule: at each step the number of ( must be greater than or equal to )
        stack<char > stk;
        unordered_map<char,char>mp = {{'[', ']'},{'(', ')'} , {'{', '}'}};
        for (int i = 0 ; i  < s.size() ;  i++) {
         if (s[i] == '(' || s[i] == '[' || s[i] == '{' ||  stk.empty()) {
            stk.push(s[i]);
         }
         else {
            if (stk.empty()) return false;
            else if (s[i] != mp[stk.top()])return false;
            stk.pop();
         }
        }
        if (stk.empty()) return true;
        return false;
    }
};

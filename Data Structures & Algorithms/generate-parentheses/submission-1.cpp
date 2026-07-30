class Solution {
public:
    void backtrack(int open, int close, int n, string &current, vector<string> &res) {
        if (current.size() == 2 * n) {
            res.push_back(current);
            return;
        }

        // Add '(' if we haven't reached max open brackets
        if (open < n) {
            current.push_back('(');
            backtrack(open + 1, close, n, current, res);
            current.pop_back();
        }

        // Add ')' if it won't exceed open brackets
        if (close < open) {
            current.push_back(')');
            backtrack(open, close + 1, n, current, res);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current = "";
        backtrack(0, 0, n, current, res);
        return res;
    }
};
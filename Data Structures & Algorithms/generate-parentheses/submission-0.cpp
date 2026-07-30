class Solution {
public:
    void generate(int rem , string & parantheses , vector<string> &  res) {
        if (rem <= 0) {
            res.push_back(parantheses);
            return;
        }
        int n = parantheses.size();
        int l = 0;
        while (l < n && parantheses[l] != '.' ) l++;
        parantheses[l] = '(';
        int r = l + 1;
        while (r < n && parantheses[r] == '.') {
            parantheses[r] = ')';
            generate(rem-1,parantheses,res);
            parantheses[r] = '.';
            r += 2;
        }
        parantheses[l] = '.';
        return;

    }
    vector<string> generateParenthesis(int n) {
        // Valid pairs can be generated like 
        // Valid + (Valid) 
        // To complete this type of paranthesis we  take 
        string parantheses(2 * n , '.');
        vector<string> res;
        generate(n, parantheses, res  );
        return res;
    }
};

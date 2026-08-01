class Solution {
private:
    void calculate(int ind , string & digits, vector<vector<char>> & digitsMap, string & temp , vector<string > & res) {
        if (ind >= digits.size()) {
            res.push_back(temp);
            return;
        } 
        for (auto & m : digitsMap[digits[ind] - '0']) {
            temp.push_back(m);
            calculate(ind + 1, digits , digitsMap , temp , res);
            temp.pop_back();
        }
        return;
    } 
public:

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<vector<char> > digitMap(10);
        digitMap[2] = {'a', 'b', 'c'};
        digitMap[3] = {'d', 'e', 'f'};
        digitMap[4] = {'g', 'h', 'i'};
        digitMap[5] = {'j', 'k', 'l'};
        digitMap[6] = {'m', 'n', 'o'};
        digitMap[7] = {'p', 'q','r', 's'};
        digitMap[8] = {'t', 'u', 'v'};
        digitMap[9] = {'w','x', 'y', 'z'};
        string temp;
        vector<string> res;
        calculate(0 , digits, digitMap , temp,res);
        return res;
    }
};

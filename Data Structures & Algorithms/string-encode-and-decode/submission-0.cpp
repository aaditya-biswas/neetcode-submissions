class Solution {
public:

    string encode(vector<string>& strs) {
        string s ="";
        for (int i = 0 ; i < strs.size();i++) {
            s +=  to_string(strs[i].size()) + '#' + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string > res;
        for (int i = 0;  i < s.size(); i++) {
           int number = 0;
           while (i < s.size() && s[i] != '#') {
            number = number * 10 + (s[i] - '0');
            i++;
           }
           if (i == s.size()) break;
           string recon = "";
           for ( int j = 0 ;j < number; j++) {
            recon += s[++i];
           } 
           res.push_back(recon);
        }
        return res;
    }
};

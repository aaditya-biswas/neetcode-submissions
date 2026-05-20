class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> bits(26,0);
        for (int i = 0 ; i < s.size() ; i++) {
            bits[s[i] - 'a']++;
            bits[t[i] - 'a']--; 
        }   
        for (int i = 0; i  < 26; i++) {
            if (bits[i]) return false;
        }
        return true;
    }
};

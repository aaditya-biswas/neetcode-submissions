class Solution {
public:
    bool isPalindrome(string s) {

        // Preprocess the string
        string processed_str = "";
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') processed_str += s[i] + ('a' - 'A');
            else if (s[i] >= '0' && s[i] <= '9') processed_str += s[i];
            else  if (s[i]  >= 'a' && s[i] <= 'z') processed_str += s[i];
             
        }
        int r = processed_str.size() -1;
        int l = 0;
        while (l < r) {
            if (processed_str[l] != processed_str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

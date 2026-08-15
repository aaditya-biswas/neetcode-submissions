class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int carry = 1;
        for (int i = n - 1; i > - 1; --i) { 
            int val = digits[i] + carry;
            res.push_back(val  % 10);
            carry = val / 10;
        }
        while (carry ) {
            res.push_back(carry % 10);
            carry /= 10;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};

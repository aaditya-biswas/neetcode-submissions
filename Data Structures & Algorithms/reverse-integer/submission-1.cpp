class Solution {
public:
    int reverse(int x) {
        int reverse_num  = 0;
        int MAX_INT = INT_MAX/10;
        int MIN_INT = INT_MIN / 10;
        while (x) {
            int modVal = x % 10;
            if (reverse_num > MAX_INT || (reverse_num == MAX_INT && modVal > 7)) return 0; 
            else if (reverse_num < MIN_INT|| (reverse_num == MIN_INT && modVal < -8 )) return 0;
            reverse_num = reverse_num * 10 + modVal;
            x /= 10;
        }
        return reverse_num;
    }
};

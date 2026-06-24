class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 31 ; i > -1;i--) {
            int val1 = (n >> i) & 1;
            res |=( val1 << (31-i));   
        }
        return res;
    }
};

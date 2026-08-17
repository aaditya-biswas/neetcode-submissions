class Solution {
public:
    int construct(int n) {
        int sum = 0;
        while (n ) {
            sum += squares[n % 10];
            n /= 10;
        }
        return sum;
    }
    int squares[10] = {0 , 1, 4, 9 ,16 , 25 , 36 , 49 , 64, 81};
    bool isHappy(int n) {
        unordered_map<int, int > mp;
        while (n != 1 && !mp.contains(n)) {
            mp[n]++;
            n = construct(n);
            
        }
        return n == 1;
    }
};

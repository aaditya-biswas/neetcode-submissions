class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0 ) return myPow(1/x , -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        double halve = myPow(x, n / 2);
        if (n % 2) return halve * halve * x;
        return halve * halve;
    }
};

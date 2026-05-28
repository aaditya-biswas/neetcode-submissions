class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxPf = 0;
        int prefixMin = prices[0];
        for (int i = 1 ; i < n ; i++) {
            mxPf = max(mxPf, prices[i]- prefixMin);
            prefixMin = min(prefixMin , prices[i]);
        }
        return mxPf;

    }
};

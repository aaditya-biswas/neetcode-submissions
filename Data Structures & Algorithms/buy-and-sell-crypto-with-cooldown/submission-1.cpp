class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int held = -prices[0];
        int sold = 0;
        int reset = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int prev_sold = sold;

            sold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(reset, prev_sold);
        }

        return max(sold, reset);
    }
};
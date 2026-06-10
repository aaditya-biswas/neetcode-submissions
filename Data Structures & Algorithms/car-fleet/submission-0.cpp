class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());

        // dp[i] stores the final arrival time of car i (accounting for crashes)
        vector<double> dp(n);
        
        // Base case: The front-most car never crashes into anyone ahead
        dp[n - 1] = (double)(target - cars[n - 1].first) / cars[n - 1].second;
        int maxFleets = 1;

        // Populate DP array from front to back
        for (int i = n - 2; i >= 0; i--) {
            double solo_time = (double)(target - cars[i].first) / cars[i].second;

            if (solo_time <= dp[i + 1]) {
                // It crashes! It matches the arrival time of the fleet ahead
                dp[i] = dp[i + 1];
            } else {
                // It doesn't crash! It forms a new fleet
                dp[i] = solo_time;
                maxFleets++;
            }
        }

        return maxFleets;
    }
};
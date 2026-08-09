class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            // If the gas total is less than the cost to travel than between than not possible
            // Greedy starting from the gas index with the most val is always profitable 
            if (accumulate(gas.begin(), gas.end() , 0) < accumulate(cost.begin() , cost.end() ,0 )) return -1;
            int n = cost.size();
            int start = n -1 ;
            int end =  n - 1;
            int tank = gas[n-1];
            do {
                if (tank < cost[end]) {
                    start = (start - 1 + n ) % n;
                    tank += (gas[start] - cost[start]); 
                }
                else {
                    tank += gas[end] - cost[end];
                    end = (end + 1) % n;
                }
            } while (start != end);
            return start;
            
        }
};

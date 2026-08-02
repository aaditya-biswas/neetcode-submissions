class Solution {
public: 
    using pt = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Network delay time 
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        vector<vector<int>> adjMat(n,vector<int> (n,INT_MAX));
        vector<int> dist(n,INT_MAX);
        for (int i = 0 ; i  < times.size() ; i++) {
            adjMat[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }        
        // Now push it to the times
        
        pq.push({0,k - 1});
        dist[k-1] = 0;
        
        while (!pq.empty()) {
            pt node = pq.top();
            pq.pop();
            if (dist[node.second] < node.first) continue;
            for (int i = 0 ; i < n; i++){
                if (adjMat[node.second][i] != INT_MAX && adjMat[node.second][i]  + node.first < dist[i]) {
                    dist[i] = adjMat[node.second][i]  + node.first;
                    pq.push({node.first + adjMat[node.second][i], i});
                
                }
            }
        }
        if (count(dist.begin(),dist.end(),INT_MAX) != 0) return -1;
        return *max_element(dist.begin(),dist.end());

    }
};

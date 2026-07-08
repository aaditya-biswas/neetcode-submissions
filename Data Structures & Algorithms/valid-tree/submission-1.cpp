class Solution {
public:
    void dfs(vector<int> & vis , vector<vector<int>> & adjList, int node) {
        vis[node] = 1; 
        for (auto & m : adjList[node]) {
            if (!vis[m]) dfs(vis , adjList , m);
        }
        return;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // Step 1. Make sure there are n - 1 edges 
        if (edges.size() != n - 1) return false;


        // Step 2. Make sure 
        vector<vector<int>> adjList(n);
        for (int i = 0 ; i < edges.size() ; i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }        
        // Step 2. Make sure the graph is a single unit
        int count = 0; 
        vector<int> vis(n,0);
        for (int i = 0  ;  i < n ; i ++ ) {
            if (count == 1 && !vis[i]) {
                return false;
            }
            if (!vis[i] ){
                dfs(vis,adjList,i);
                count++;
            }
        }
        return true;
    }

};

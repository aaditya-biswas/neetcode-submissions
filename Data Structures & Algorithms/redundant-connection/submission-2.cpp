class DSU {
    public:
    vector<int> size;
    vector<int> parent;
    DSU(int n) {
        size.assign(n + 1,1);
        parent.assign(n + 1,-1);
        for (int i  = 1 ; i <= n ; i++) {
            parent[i] = i;
        }
    
    }
    int find(int node) {
        if (parent[node] ==  node) return node;
        return parent[node] = find(parent[node]);   
    }
    void unn(int x , int y) {
        int  p1 = find(x);
        int  p2 = find(y);
        if (size[p1] > size[p2 ] ) {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else {
            parent[p1] = p2 ;
            size[p2] += size[p1];
        }
        return;
    }


};


class Solution {
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            // Check if both are in vis 
            int n =  edges.size();
            DSU dsu(n);
            vector<int > vis(n + 1, 0);
            vector<int> res;
            for ( int i = 0 ;  i < n ; i ++ )  {
                int u = edges[i][0] , v = edges[i][1];
                if (dsu.find(u) == dsu.find(v)) res = {u , v};
                dsu.unn(u,v);
            }
    
        return res;
    }
};

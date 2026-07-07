class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> degrees(numCourses,0);
        vector<int> res;
        for (auto &m : prerequisites) {
            adjList[m[1]].push_back(m[0]);
            degrees[m[0]]++;
        }
        // Multi Source BFS
        queue<int > q;
        int size = 0;
        for (int i = 0 ; i < numCourses ; i ++) {
            if (degrees[i] == 0) {
                q.push(i);
                res.push_back(i);
                size++;
            }
        }
        // GIVE  A DAG 
        while (!q.empty()) {
            int top = q.front();
            cout << top;
            q.pop();

            for (auto m : adjList[top]) { 
                degrees[m]--;
                if (degrees[m] == 0) {
                    q.push(m);
                    res.push_back(m);
                    size++;
                }
            }
        }

        // 
        if (size != numCourses) return {};
        return res;
    }
};

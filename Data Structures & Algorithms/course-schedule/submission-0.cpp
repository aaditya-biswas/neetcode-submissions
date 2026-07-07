class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Give a DAG
        vector<vector<int>> adjList(numCourses);
        vector<int> degrees(numCourses,0);
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
                    size++;
                }
            }
        }

        // 
        if (size == numCourses) return true;
        return false;
    }
};

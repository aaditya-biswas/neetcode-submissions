class Solution {
public:
    bool check(string & a , string & b ) {
        int diff = 0;
        int n = a.size();
        for (int i = 0 ; i < n ; i++ ) {
            if (a[i] != b[i]) diff++;
        }
        return diff == 1;
    }
    vector<vector<int>> makeGraph(vector<string> & wordList) {
        int n = wordList.size();
        vector<vector<int>> adjList(n);
        for (int i = 0 ; i < n ; i ++) {
            for ( int j = i + 1 ; j < n ; j++) {
                if (check(wordList[i],wordList[j])) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);

                }
            }
        }
        return adjList ;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> vis;
        wordList.push_back(beginWord);
        vector<vector<int >> adjList;
        int n = wordList.size();
        adjList =  makeGraph(wordList);
        queue<int > q;
        q.push(n - 1);
        vis[beginWord] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto  m : adjList[node]) {
                if (!vis.contains(wordList[m])) {
                    vis[wordList[m]] = vis[wordList[node]] + 1;
                    q.push(m);
                }
            }
        }
        if (!vis.contains(endWord)) return 0;
        return vis[endWord]  + 1;

    }
};

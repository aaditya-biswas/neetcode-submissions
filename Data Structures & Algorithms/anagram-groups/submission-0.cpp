
class Node {
    public:
        char c;
        int  isEndPos;
        vector<Node *> next;
        Node(char ch) {
            c= ch;
            isEndPos = -1;
            next.assign(26,nullptr);
        }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        Node * rt = new Node('/'); 
        int length = 0;
        vector<vector<string> > res;
        for (int i =  0 ; i  < strs.size() ;i++) {
            string cur_string = strs[i];
            sort(cur_string.begin(),cur_string.end());
            Node * cur = rt;
            for (int j = 0; j < cur_string.size(); j++) {
                if (cur->next[cur_string[j] - 'a'] == nullptr) {
                    Node * a  = new Node(cur_string[j]);
                    cur->next[cur_string[j] - 'a'] = a;
                }
                cur  = cur->next[cur_string[j] - 'a'];
            }
            if (cur->isEndPos == -1) {
                cur->isEndPos = length;
                res.push_back({strs[i]});
                length++;
            }
            else {
                res[cur->isEndPos].push_back(strs[i]);
            }

        }
        return res;
    }
};

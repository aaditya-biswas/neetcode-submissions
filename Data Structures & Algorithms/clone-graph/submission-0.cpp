/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * cloneHelper(Node * node, unordered_map<Node* , Node * > & mp) {
        Node * a = new Node(node->val);
        mp[node] = a; 
        for (auto &m : node->neighbors) {
            if (mp.count(m)) a->neighbors.push_back(mp[m]);
            else a->neighbors.push_back(cloneHelper(m,mp));
        }

        return a;
    }
    Node* cloneGraph(Node* node ) {
        if (node == nullptr) return nullptr;
        unordered_map<Node* , Node * > mp;
        return cloneHelper(node,mp) ; 
        
    }
};

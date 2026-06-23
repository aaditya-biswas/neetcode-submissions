/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Codec {
public:
    // Helper to serialize tree
    void _helper_serialize(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        _helper_serialize(root->left, s);
        _helper_serialize(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        _helper_serialize(root, s);
        return s;
    }

    // Helper to deserialize tree
    TreeNode* _helper_deserialize(string& data, int& ind) {
        if (ind >= data.size()) return nullptr;
        
        // Extract the next value
        string val = "";
        while (ind < data.size() && data[ind] != ',') {
            val += data[ind];
            ind++;
        }
        ind++; // skip comma
        
        if (val == "N") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = _helper_deserialize(data, ind);
        root->right = _helper_deserialize(data, ind);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind = 0;
        return _helper_deserialize(data, ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using pt  =  pair<int,int>;
class Solution {
public:
    int calculateDepth(TreeNode * root, unordered_map<TreeNode *,pt>  & path_size) {
        if (root == nullptr ) {
            return 0;
        }
        int left_depth = calculateDepth(root->left, path_size);
        int right_depth = calculateDepth(root->right, path_size);
        path_size[root] =  {left_depth,right_depth};
        return  1 + max(left_depth,right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // Int longest path between two nodes from the left 
        // Int longest path between the two nodes from the right
        unordered_map<TreeNode *,pt>  path_size;
        calculateDepth(root, path_size);
        return solve(root, path_size) - 1;
    }
    int solve(TreeNode  * root,unordered_map<TreeNode *,pt>   & path_size) {
        if (root == nullptr) return 0;
        int left = solve(root->left, path_size);
        int right = solve(root->right, path_size);
        return max({left,right,1 + path_size[root].first + path_size[root].second}); 
    }
};

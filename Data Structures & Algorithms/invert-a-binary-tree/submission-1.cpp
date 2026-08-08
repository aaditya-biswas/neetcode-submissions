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

class Solution {
public:
    TreeNode* invertTree(TreeNode* rt) {
        if (rt == nullptr) return rt;
        TreeNode * temp = rt->left;
        rt->left = rt->right;
        rt->right  = temp;
        invertTree(rt->left);
        invertTree(rt->right);
        return rt;
    }
};

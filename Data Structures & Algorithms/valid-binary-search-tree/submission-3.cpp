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
    bool check(int maxVal , int minVal ,TreeNode * root ) {
        if (root == nullptr ) return true;
        if (root->val >= maxVal || root->val <=minVal) {
            return false;
        } 
        return check(root->val,minVal, root->left) && check(maxVal,root->val, root->right);
    }
    bool isValidBST(TreeNode* root) {
        return check(INT_MAX,INT_MIN, root);
    }
};

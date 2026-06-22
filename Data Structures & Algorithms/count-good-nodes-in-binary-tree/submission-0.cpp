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
    void calculate(int & sum , TreeNode * root ,int maxVal) {
        if (root == nullptr) return;
        if (root->val >= maxVal) {
            sum++;
        }
        calculate(sum,root->left,max(maxVal,root->val));
        calculate(sum,root->right,max(maxVal,root->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        // Top down traversal and for each node maintain a list of maxVal
        int sum = 0;
        int maxVal = INT_MIN;
        ;calculate(sum, root , maxVal);
        return sum;
    }
};

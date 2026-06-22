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
    void calculate(TreeNode * root , vector<int >  & sol ,int depth) {
        if (root == nullptr) return;
        if (depth > sol.size()) sol.push_back(root->val);
        calculate(root->right,sol,depth+1);
        calculate(root->left,sol,depth+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>  sol;
        calculate(root,sol,1);
        return sol;
    }  
};

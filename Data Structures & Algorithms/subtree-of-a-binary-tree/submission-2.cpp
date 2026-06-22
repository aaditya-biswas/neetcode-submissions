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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        return (p && q && p->val ==  q->val &&  isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;

        return (root  && subRoot && (isSameTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)));
        return false;
    }
    
};

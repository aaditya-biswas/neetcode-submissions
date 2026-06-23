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
    int calculateSize( TreeNode * root , unordered_map<TreeNode * ,pair<int,int>> & mp) {
        if (root == nullptr) return 0;
        int left = calculateSize(root->left,mp);
        int right = calculateSize(root->right,mp);
        mp[root] = {left,right};
        return 1+ left+ right;
    }
    int traverse(TreeNode * root,unordered_map<TreeNode * , pair<int,int>> &mp, int k) {
        if (k == mp[root].first + 1) return root->val;
        if (k > mp[root].first + 1 ) return traverse (root->right, mp,k- mp[root].first -1 );
        return traverse(root->left,mp,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode * , pair<int,int>> mp;
        calculateSize(root,mp);
        return traverse(root,mp,k);
        
    }
};

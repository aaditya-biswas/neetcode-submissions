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
/*


*/
class Solution {
public:
    TreeNode * calculate(vector<int> & preorder,vector<int>  & inorder  , unordered_map<int,int> & mp, int ind,int l ,int r ) {
        if (l > r || l < 0 || r > preorder.size()) return nullptr;
        else if ( l == r ) return  new TreeNode(preorder[ind]);
        TreeNode * root  = new TreeNode(preorder[ind]);
        // We have obtained the index of the inorder element 
        int idx = mp[preorder[ind]];
        int left_size = idx - l ;
        int right_size = r - idx;
        root->left = calculate(preorder,inorder,mp, ind + 1,l,idx  -1 );
        root->right = calculate(preorder,inorder,mp, ind + left_size + 1, idx + 1, r  );
        // Number of indices on the left of the array 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Step 1. Make a map for the  the inorder element
        unordered_map<int,int > mp;
        for (int i = 0 ; i < inorder.size() ;i++ ) {
            mp[inorder[i]] = i;
        }

        return calculate(preorder,inorder ,mp, 0,0,preorder.size()-1);

    }
};

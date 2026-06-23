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
    // There are 2 cases  
    // Either the maximum path is formed via the two branches of this node
    // Or the maximum path is formed via the ancestor using the leftSum or rightSum of the current Path
    // Hence we traverse recursively and try to find the best possible path to move upward
    // Also we keep a track of maxVal such that we are able to calculate the intermediate value in the tree and it is not lost 
    int calculate(TreeNode  * root , int & maxVal) {
        if (  root == nullptr) return -1001;
        int leftPathSum = calculate(root->left,maxVal);
        int rightPathSum = calculate(root->right,maxVal);
        int returnVal = max({1LL* root->val,1LL*root->val + leftPathSum,1LL*root->val + rightPathSum });
        maxVal = max({maxVal,leftPathSum  + root->val + rightPathSum, root->val,root->val + leftPathSum,root->val + rightPathSum}); 
        cout << "Processing node "  << root->val << " Sum " << root->val + leftPathSum + rightPathSum << " Left Value " << leftPathSum << " Right Value " << rightPathSum << " Returning value " << returnVal  << endl ;
        return returnVal;

    }
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        calculate(root,maxVal);
        return maxVal;
    }
};

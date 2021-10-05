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
    int sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return sum;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        int l = max(0, helper(root->left)); 
        int r = max(0, helper(root->right));
        sum = max(sum, l+r+root->val);
        return max(l, r) + root->val;
    }
};

/*
We have 2 options for a node (similar to diameter of  tree)
1. Assume the max path passes from the current node
2. Assume max path does not passes from the current node. In this case pass the max(l, r) to the calling function

We take max(0, root->left) cuz we don't want to add negative values with root's val when processing the current node
*/
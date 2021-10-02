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
    TreeNode *func(TreeNode* root){
        if(!root)   return root;
        if(!root->left && !root->right)  return root;
        
        auto l = func(root->left);        
        auto r = func(root->right);             
        
        if(l){
            auto x = l;
            while(x->right){
                x = x->right;
            }
            x->right = r;
            root->right = l;
            root->left = NULL;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root = func(root);
    }
};
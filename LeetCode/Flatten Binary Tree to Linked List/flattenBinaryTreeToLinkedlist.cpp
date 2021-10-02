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
        
        //if tree is empty then return null
        if(!root)   return root;
        
        //if tree has only root node, then return the node itself
        if(!root->left && !root->right)  return root;
        
        //calling the left subtree
        auto l = func(root->left);
       
        //calling the right subtree
        auto r = func(root->right);             
        
        //if left sub-tree exists
        if(l){
            auto x = l;
            //then attach the nodes to the right till the node exists
            while(x->right){
                x = x->right;
            }
            //make the x node right node point to right sub-tree
            x->right = r;
            //make the root node right node point to left sub-tree
            root->right = l;
            //make the root node left node point to NULL
            root->left = NULL;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        //calling the helper function
        root = func(root);
    }
};

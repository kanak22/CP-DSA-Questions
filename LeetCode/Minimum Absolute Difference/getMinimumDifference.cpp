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
    int ans = INT_MAX;
    void func(TreeNode* root,int &v){
        if(!root)   return;
        if(!root->left && !root->right){
            if(v != -1)
                ans = min(ans,abs(v-root->val));
            v = root->val;
            return;
        }
        func(root->left,v);
        if(v != -1)
            ans = min(ans,abs(v-root->val));
        v = root->val;
        func(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        int v = -1;
        func(root,v);
        return ans;
    }
};
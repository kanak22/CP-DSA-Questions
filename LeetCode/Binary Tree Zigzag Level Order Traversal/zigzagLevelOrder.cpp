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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        queue<TreeNode *> q;
        q.push(root);
        int x = 1;
        while(!q.empty()){
            vector<int> v;
            int sz = q.size();
            while(sz--){
                auto tp = q.front();
                q.pop();
                v.push_back(tp->val);
                if(tp->left){
                    q.push(tp->left);
                }
                if(tp->right){
                    q.push(tp->right);
                }
            }
            if(x){
            }
            else{
                reverse(v.begin(),v.end());
            }            
            ans.push_back(v);
            x ^= 1;
        }
        return ans;
    }
};
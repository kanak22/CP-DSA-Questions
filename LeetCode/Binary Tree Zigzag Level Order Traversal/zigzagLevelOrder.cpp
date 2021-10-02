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
        //ans vector to store final zigzag order
        vector<vector<int>> ans;
        
        //if tree is empty return empty ans vector
        if(!root)   return ans;
        
        //declaring queue traverse level order-wise
        queue<TreeNode *> q;
        
        //pushing root node
        q.push(root);
        
        //maintaining alternate turns by x variable
        int x = 1;
        
        //loop traverses till queue isn't empty
        while(!q.empty()){
            
            //declaring vector which will store list level-wise
            vector<int> v;
            
            //declaring sz ehich will help in order to traverse level-wise
            int sz = q.size();
           
            while(sz--){
                
                //extracting the front element
                auto tp = q.front();
                q.pop();
                
                //pushing the value in v vectr
                v.push_back(tp->val);
                
                //if left node exists then pushing the left node
                if(tp->left){
                    q.push(tp->left);
                }
                
                //if right node exists then pushing the right node
                if(tp->right){
                    q.push(tp->right);
                }
            }
            
            //if x is 1 then do nothing
            if(x){
            }
            else{
                //else we should reverse the v vector
                reverse(v.begin(),v.end());
            }            
            
            //pushing the v vector into ans
            ans.push_back(v);
            
            //alternating value of x between 1 and 0
            x ^= 1;
        }
        return ans;
    }
};

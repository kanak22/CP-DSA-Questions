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
 
// check this link for more clarity to my solution -  https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

class Solution {
    public:

        int dfs(TreeNode* root,int &ans){
            if(!root)return 0;

            int l = dfs(root->left,ans);
            int r = dfs(root->right,ans);

            ans += abs(l) + abs(r); 
            // for example if we get l = 3 and r = -1 then it means that left subtree of curr node has 3 extra coins and right subtree has 1 coin less so what we can do is keep one coin for current node and rest all the coins forward it to parent node
            //So total moves needed for current node with l = 3 and r = -1 is abs(3) + abs(-1) i.e 4 as 3 moves to move 3 excess coins from left subtree to current node and moving one coin from current node to right subtree as right subtree is in need of one coin

            return root->val + l + r - 1; // this statement represents how much coins are being forwarded from current node to its parent node
        }

        int distributeCoins(TreeNode* root) {
            int ans = 0; // variable to keep track of total number of moves 

            dfs(root,ans);

            return ans;
        }
    };
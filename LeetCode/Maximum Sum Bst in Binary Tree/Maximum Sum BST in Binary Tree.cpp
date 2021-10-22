/*
Question Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
Given a binary tree root, return the maximum sum of all keys of any sub-tree
which is also a Binary Search Tree (BST).
*/

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

class Solution
{
public:
    struct pair
    {
        bool bst;
        int maxsum;              // max sum possible till current root
        int sum, minVal, maxVal; // current subtree info
        pair(bool check, int ms, int s, int min, int max)
        {
            bst = check;
            maxsum = ms;
            sum = s;
            minVal = min;
            maxVal = max;
        }
    };

    /* 1.For tree rooted at particular node to be BST:
        --> Left Child is BST
        --> Right Child is BST
       2.Current node has to be BST itself:
        --> node value > max value in Left Child
        --> node value < min value in Right Child */
    struct pair solve(TreeNode *root)
    {
        struct pair p = {true, INT_MIN, 0, INT_MAX, INT_MIN};
        if (root == NULL)
            return p;

        struct pair lp = solve(root->left);
        struct pair rp = solve(root->right);

        int val = root->val;

        bool isBST = (val > lp.maxVal && val < rp.minVal && lp.bst && rp.bst); // check if current node form BST

        int curMaxSum, curSum, curMin, curMax;
        if (isBST)
        {
            curSum = lp.sum + rp.sum + val;
            curMaxSum = max(curSum, max(lp.maxsum, rp.maxsum));
            curMin = min(val, lp.minVal);
            curMax = max(val, rp.maxVal);
        }
        else
        {
            curSum = 0;
            curMaxSum = max(lp.maxsum, rp.maxsum);
            curMin = INT_MIN;
            curMax = INT_MAX;
        }
        struct pair cur = {isBST, curMaxSum, curSum, curMin, curMax};
        return cur;
    }

    int maxSumBST(TreeNode *root)
    {
        return max(0, solve(root).maxsum);
    }
};

// Time Complexity : O(N), where N = Numbers nodes in the tree. Because just doing 1 DFS on tree
// Space Complexity : O(N), Because of the recusive function call stack
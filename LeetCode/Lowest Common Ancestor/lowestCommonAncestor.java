/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        // if there is no more node, return null
        if(root == null) return root;
        
        // if we found p or q, return the node
        if(root.val == p.val || root.val == q.val) return root;
        
        // recursion to left branch and right branch
        TreeNode leftNode = lowestCommonAncestor(root.left, p, q);
         
        TreeNode rightNode = lowestCommonAncestor(root.right, p, q);
        
        // if we found both node, then we can return the root as our LCA
        if(leftNode != null && rightNode != null) return root;
        
        // otherwise we return either node back to top (or both null)
        return leftNode != null ? leftNode : rightNode;  
    }
}
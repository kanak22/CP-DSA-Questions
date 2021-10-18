//Given an integer n, return all the structurally unique BST's (binary search trees), 
//which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
//Example 
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    static List<TreeNode> generate(int start,int end){
        List<TreeNode> list=new ArrayList<>();
        if(start>end){
            list.add(null);
        }
        for(int ind=start;ind<=end;ind++){
            List<TreeNode> left=generate(start,ind-1);
            List<TreeNode> right=generate(ind+1,end);
            for(TreeNode lnode:left){
                for(TreeNode rnode:right){
                    TreeNode root=new TreeNode(ind);
                  root.left=lnode;
                  root.right=rnode;
                  list.add(root);
                }
            }
        }
        return list;
        
    }
    public List<TreeNode> generateTrees(int n) {
        return generate(1,n);
    }
}

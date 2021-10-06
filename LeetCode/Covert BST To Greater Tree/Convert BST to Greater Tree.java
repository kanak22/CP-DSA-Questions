class Solution {
    static int sum=0;
    public void convertToGreater(TreeNode root){
       if(root==null)return;
       if(root.left==null && root.right==null){
           int prev=root.val;
           root.val+=sum;
           sum+=prev;
           return; 
       };
       convertToGreater(root.right);
       int prev=root.val;
       root.val+=sum;
       sum+=prev;
       convertToGreater(root.left);
    }
    public TreeNode convertBST(TreeNode root) {
        convertToGreater(root);
        sum=0;//restting to default value since this is a static variable
        return root;
    }
}
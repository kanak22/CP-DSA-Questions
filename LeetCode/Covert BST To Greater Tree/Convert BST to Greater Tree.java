class Solution {
    //global variable to store sum
    static int sum=0;
    
    public void convertToGreater(TreeNode root){
        
        //if root is null then return 
       if(root==null)return;
        
        //if it is a leaf node
       if(root.left==null && root.right==null){
           //temporary variable to store root value
           int prev=root.val;
           //adding sum value to root
           root.val+=sum;
           //adding prev value to sum
           sum+=prev;
           return; 
       };
       //calling right subtree
       convertToGreater(root.right);
        //temporary variable to store root value
       int prev=root.val;
        //adding sum value to root
       root.val+=sum;
        //adding prev value to sum
       sum+=prev;
        //calling left sub tree
       convertToGreater(root.left);
    }
    public TreeNode convertBST(TreeNode root) {
        //calling helper function
        convertToGreater(root);
        
        sum=0;//restting to default value since this is a static variable
        
        return root;
    }
}

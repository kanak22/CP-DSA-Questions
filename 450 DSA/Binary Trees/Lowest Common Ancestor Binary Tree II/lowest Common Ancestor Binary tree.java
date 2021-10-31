//Only the main solution function is added and the driver function codes are not included 
class Solution
{
    //Function to return the lowest common ancestor in a Binary Tree.

    Node lca(Node root, int n1,int n2) 
    {
        if(root == null)//base case when we reach to the null node 
            return null;//returning back 
        
        if((root.data == n1 ) || (root.data == n2))//when we are founding the desired node we are returning it and deleting the current activation record 
            return root;
        
        Node left= lca(root.left,n1,n2);//we are traversing the left sub-tree 
        Node right= lca(root.right,n1,n2);//and then the right subtree is traversed 
        
        if((left != null) && (right != null))//when we got the lowest commont node from left and rigt subtree 
            return root;
        
        if((left == null )&& (right == null))//when both(left,right) are null we return null as there is no chance of getting our desired node
            return null;
        
        return (left != null)?left: right;//when one of the node is null it returns the node without null in order to compare with the next node 
    
	}
}


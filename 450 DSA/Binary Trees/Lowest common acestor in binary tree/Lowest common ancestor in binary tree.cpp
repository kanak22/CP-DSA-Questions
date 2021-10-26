/*
Link to the question:
https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Given a Binary Tree with all unique values and two nodes value n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2

*/
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.

    // global variable ans to store the answer.
    Node *ans=NULL;


    bool solve(Node *root,int n1,int n2)
    {
        // if root is null return false.
        if(!root)
        {
            return false;
        }
        // call the solve function for the left child
        // returns true if it finds any on the node in the left subtree
        bool l=solve(root->left,n1,n2);

        // call the solve function for the right child
        bool r=solve(root->right,n1,n2);

        // if root is one of the nodes then
        if(root->data==n1 || root->data==n2)
        {
            // check if we find the other node in its left or right subtree
            if(l || r)
            {
                // if found then lca becomes the root.
                // change ans from null to root.
                ans=root;

                return true;
            }
            return true;
        }
        // if both the nodes are found in the left and right subtree then   
        if(l && r)
        {
            // if ans is null then only the root will be lca else root will be the common ancestor but not lowest common ancestor.
            if(!ans)
            {
            ans=root;
            }
            
            return true;
        }
        // if node found in left subtree return true
        else if(l)
        {
            return true;
            
        }
        // if node found in right subtree return true
        else if(r)
        {
            return true;
        }
        // if no node found in left and right return false
        return false;
    }
    
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        // if the root itself is null then return NULL
        if(!root)
        {
            return NULL;
        }
        
        // if any one of the given two nodes is the root then LCA of that two nodes will obviously be the root node.
        if(n1==root->data || n2==root->data)
        {
            return root;
        }     

        // call the solve function passing the root and the nodes whose lca has to be calculated.
        bool a1=solve(root,n1,n2);

        // if both the nodes are not present then a1 will be false hence return NULL
        if(!a1)
        {
            return NULL;
        }
        // else return the ans 
        return ans;
        
    }
};
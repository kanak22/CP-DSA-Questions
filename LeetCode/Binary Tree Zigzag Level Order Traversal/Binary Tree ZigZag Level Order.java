import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        //declaring two stacks
        Stack<TreeNode> st1 = new Stack<>();
        Stack<TreeNode> st2 = new Stack<>();
        
        //declaring an array list
        List<List<Integer>> list = new ArrayList<>();
        
        //pushing root node in stack1
        st1.push(root);
        
        //while one of the stack is not empty
        while (!st1.isEmpty() || !st2.isEmpty()) {
            
            //declaring two array lists
            List<Integer> li = new ArrayList<>();
            List<Integer> lis = new ArrayList<>();
            
            //while stack 1 doesnot becomes empty
            while (!st1.isEmpty()) {
                //pop the element and add to the list 1
                TreeNode curr = st1.pop();
                li.add(curr.val);
                //if left node of current is not null then push it in stack 2 
                if (curr.left != null) st2.push(curr.left);
                
                //if right node of current is not null then push it in stack 2 
                if(curr.right!=null) st2.push(curr.right);
            }
            
            //while stack 2 doesnot becomes empty
            while (!st2.isEmpty()) {
                //pop the element and add to the list 2
                TreeNode curr = st2.pop();
                lis.add(curr.val);
                //if left node of current is not null then push it in stack 1 
                if (curr.left != null) st1.push(curr.left);
                //if left node of current is not null then push it in stack 1
                if(curr.right!=null) st1.push(curr.right);
            }
            //while list 1 is not emoty add the value in answer list
            if(!li.isEmpty()) list.add(li);
            
            //while list 2 is not emoty add the value in answer list
            if (!lis.isEmpty()) list.add(lis);
        }
        
        //return final list
        return list;
    }
}

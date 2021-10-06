import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Stack<TreeNode> st1 = new Stack<>();
        Stack<TreeNode> st2 = new Stack<>();
        List<List<Integer>> list = new ArrayList<>();
        st1.push(root);
        while (!st1.isEmpty() || !st2.isEmpty()) {
            List<Integer> li = new ArrayList<>();
            List<Integer> lis = new ArrayList<>();
            while (!st1.isEmpty()) {
                TreeNode curr = st1.pop();
                li.add(curr.val);
                if (curr.left != null) st2.push(curr.left);
                if(curr.right!=null) st2.push(curr.right);
            }
            while (!st2.isEmpty()) {
                TreeNode curr = st2.pop();
                lis.add(curr.val);
                if (curr.left != null) st1.push(curr.left);
                if(curr.right!=null) st1.push(curr.right);
            }
            if(!li.isEmpty()) list.add(li);
            if (!lis.isEmpty()) list.add(lis);
        }
        return list;
    }
}
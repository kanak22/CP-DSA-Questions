/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 public class Pair implements Comparable<Pair>{
        int listIndex;
        ListNode nodeIndex;
        int nodeVal;
        
        Pair(int listIndex, ListNode nodeIndex, int nodeVal){
            this.listIndex = listIndex;
            this.nodeIndex = nodeIndex;
            this.nodeVal = nodeVal;
        }
        
        public int compareTo(Pair o){
            return this.nodeVal - o.nodeVal;
        }
}
    


class Solution {
    
    public ListNode mergeKLists(ListNode[] lists) {        
        
        // solution O(n)
        if(lists.length == 0)
            return null;
        
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        // putting list index and first value of each list with their index in priority queue
        for(int i=0; i<lists.length; i++){
            if(lists[i]!=null)
            {                   // listIndex, nodeIndex, nodeval
                Pair pair = new Pair(i, lists[i], lists[i].val);
                pq.add(pair);
            } 
        }
        
        ListNode head = new ListNode(0);
        ListNode tmp = head;
        
        while(pq.size()>0){
            Pair pair = pq.remove();
            ListNode newList = new ListNode(pair.nodeVal);
            tmp.next = newList;
            tmp = tmp.next;
            
            // increment the node index
            pair.nodeIndex = pair.nodeIndex.next;
            // checking either next node index is existing or not
            if(pair.nodeIndex!=null){
                // update the node val with next node val
                pair.nodeVal = pair.nodeIndex.val;
                pq.add(pair);
            }
        }
        tmp.next = null;
        return head.next;
    }
}
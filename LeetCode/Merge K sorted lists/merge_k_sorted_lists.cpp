/* APPROACH TOWARDS THE SOLUTION
1. Basic idea is to add one list to another.
2. Consider the below mentioned conditions:
    -> The list 1 is empty. Then list 2 is the result.
    -> If the current element in list 1 is greater than current element in list 2 then, insert current element in list 2 before current element of list 1.
    -> If current element in list 1 is greater than current element in list 2, iterate to the next element in list 1 and compare again.
    -> Repeat Step 2 and Step 3 in a loop, until list 2 is empty.

    In this approach, one node is used to hold the head of the result (for output), another node is used for the tail of the result list (for insertion), every time check:
    (1) The empty case, 
    (2) The value comparison
    (3) Insert proper node into the result list 
*/
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        ListNode* head=new ListNode(0);
        if (lists.size()==0){return NULL;}
        head->next = lists[0];
        ListNode *p;
        ListNode *q;
        for (int i=1;i<lists.size();i++){
            p = head;
            q = lists[i];
            while (q){
                if (!p->next){
                    p->next = q;
                    break;
                }
                if (p->next->val<q->val){
                    p=p->next;
                }else{
                    ListNode *l = p->next;
                    p->next = q;
                    q=q->next;
                    p->next->next = l;
                    p=p->next;
                }
            }
        }
        return head->next;
    }
};

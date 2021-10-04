#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class comp{
        public:
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //if there is not linked list in the vector
        if(lists.size() == 0) return nullptr;
        
        //make a dummy node
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
    
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;
        //now push the k list in heap if not NULL
        for(int i = 0;i<lists.size();i++){
            if(lists[i]){
                heap.push(lists[i]);
            }
        }

        //while heap is not empty
        while(!heap.empty()){
            ListNode* temp = heap.top();
            heap.pop();
            curr->next = temp;//for first time temp becomes the new Head of the merged ll
            curr = temp; //move current to next smallest
            //now if the next of temp exist it will be pushed to heap
            if(temp->next)
                heap.push(temp->next);
        }
        return dummy->next;
    }
};
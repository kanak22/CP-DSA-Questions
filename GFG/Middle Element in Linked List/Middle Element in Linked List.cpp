/*
Question Link : https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.

*/

    int getMiddle(Node *head)
    {
        // Your code here
        int i=0,len=0,index=0;
        Node *tmp = head;
        while(tmp != NULL)  // finding length of linked list
        {
           len++;
           tmp = tmp->next;
        }
        if(len == 0)
         return -1;
       
        index = (len/2);
            
        Node *tmp1 = head;
        while(i < index)
        {
           tmp1 = tmp1->next;
           i++;
        }
        return tmp1->data;
    }

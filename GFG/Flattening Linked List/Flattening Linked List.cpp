/*Question Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1# */

/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
*/
/*
Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)

*/
// Solution :

    Node*merge(Node*l1,Node*l2){
        Node*ans=new Node(0);  //create dummy node 
        Node*one=ans;
        while(l1 && l2){
            if(l1->data<=l2->data){ // check if both l1 and l2 have data and if data of l1->data<=l2->data
                one->bottom=l1; //link l1 to one 
                l1=l1->bottom; //move to next l1
                one=one->bottom; 
            }
            else{
                one->bottom=l2;  //link l2 to one
                l2=l2->bottom;
                one=one->bottom;
            }
        }
        
        while(l1){ //if we have only l1 
            one->bottom=l1;
            one=one->bottom;
            l1=l1->bottom;
            
        }
        
        while(l2){ // if we have only l2 
            one->bottom=l2;
            l2=l2->bottom;
            one=one->bottom;
        }
        one->bottom=NULL;
        return ans->bottom;
    }
    
Node *flatten(Node *root)
{
   // Your code here
   
   Node*ans=new Node(0); //create a dummy node 
      if(root==NULL|| root->next==NULL) return root;

   Node*one=ans;
   Node*l2=root;
   while(l2!=NULL){
       one->bottom=merge(one->bottom,l2); 
    //    we merge the list and keep linking them 
       l2=l2->next;
   }
   return ans->bottom;
   
}



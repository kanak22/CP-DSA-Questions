/*
    Note: This question has does not allow to code from scratch so I am writing only decode_huff function

    Approach:
        We are given a huffman encoded string as input and root node of the huffman tree.

        1. Whenever we encounter 0 in string we move to left child of the tree 
        and if data is present there we print the data and then again move back to the root.
        2. Similarly when we encounter 1 in string we move to right child of the tree 
        and if data is present there we print the data and then again move back to the root.
        3. If data is not present, we do not need to move back to root again.
*/

void decode_huff(node * root, string s) {
    node* temp=root;
    for(int i=0;i<s.length();i++){
        temp=(s[i]=='0')?temp->left:temp->right;
        if(temp->data){
            cout<<temp->data;
            temp=root;
        }
    }
}
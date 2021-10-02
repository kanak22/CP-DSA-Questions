#include<bits/stdc++.h>

using namespace std;

// BST(Binary Search Tree) Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

// A utility function to create a new BST Node
TreeNode *newNode(int item) {
    TreeNode *temp = new TreeNode;
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive function to transform a BST to Greater Tree.
// This function traverses the tree in reverse inorder so that we have visited
// all greater key nodes of the currently visited node
void transformBSTUtil(TreeNode *node, int *acc_sum) {
    // Base Case
    if(node == NULL) return;

    // Recur for right subtree
    transformBSTUtil(node->right, acc_sum);

    // Update the cur node's sum
    node->val += *(acc_sum);

    // Update the cummulative sum
    *(acc_sum) = node->val;

    // Recur for left subtree
    transformBSTUtil(node->left, acc_sum);
}

// A wrapper function over the transformBSTUtil()
void transformBST(TreeNode *root) {
    int acc_sum = 0;
    transformBSTUtil(root, &acc_sum);
}

// A utility function to print the inorder traversal of the BST
void printInorder(TreeNode *root) {
    // Base Case
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    TreeNode *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);

    cout << "Inorder Traversal of given tree\n";
    printInorder(root);

    transformBST(root);

    cout << "\n\nInorder Traversal of transformed tree\n";
    printInorder(root);

    return 0;
}
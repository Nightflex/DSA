#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Traverse the left subtree
    inorderTraversal(root->left);
    
    // Visit the root
    printf("%d ", root->data);
    
    // Traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder traversal of the binary tree:\n");
    inorderTraversal(root);
    
    return 0;
}

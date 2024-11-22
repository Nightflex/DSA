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

// Preorder traversal function
void preorderTraversal(struct Node* node) {
    if (node == NULL)
        return;
    
    // Visit the root
    printf("%d ", node->data);

    // Traverse the left subtree
    preorderTraversal(node->left);

    // Traverse the right subtree
    preorderTraversal(node->right);
}

int main() {
    // Creating nodes and forming a tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder traversal of the binary tree is:\n");
    preorderTraversal(root);

    return 0;
}

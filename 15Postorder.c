#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform postorder traversal of the tree
void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    // Traverse the left subtree
    postorderTraversal(node->left);

    // Traverse the right subtree
    postorderTraversal(node->right);

    // Visit the root node
    printf("%d ", node->data);
}

// Driver code
int main() {
    /* Constructing the following binary tree
              1
             / \
            2   3
           / \
          4   5
    */
    struct Node* root = createNode(9);
    root->left = createNode(7);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(1);

    printf("Postorder traversal of the binary tree is: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

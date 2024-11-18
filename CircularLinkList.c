#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;  // Points to itself (circular property)
    return newNode;
}

// Insert at front
void insertFront(Node** tail, int data) {
    Node* newNode = createNode(data);
    if (!*tail) {
        *tail = newNode;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
}

// Insert at end
void insertEnd(Node** tail, int data) {
    insertFront(tail, data);
    *tail = (*tail)->next; // Update tail to the new node
}

// Insert at position
void insertAtPos(Node** tail, int pos, int data) {
    if (pos <= 1 || !*tail) {  // Insert at front if position <= 1 or list is empty
        insertFront(tail, data);
        return;
    }
    Node* temp = (*tail)->next;
    for (int i = 1; i < pos - 1 && temp != *tail; i++)
        temp = temp->next;
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == *tail) *tail = newNode; // Update tail if inserted at the end
}

// Delete from front
void deleteFront(Node** tail) {
    if (!*tail) {
        printf("List is empty.\n");
        return;
    }
    Node* head = (*tail)->next;
    if (*tail == head) { // Single node case
        free(head);
        *tail = NULL;
    } else {
        (*tail)->next = head->next;
        free(head);
    }
}

// Delete from end
void deleteEnd(Node** tail) {
    if (!*tail) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = (*tail)->next;
    if (temp == *tail) { // Single node case
        free(temp);
        *tail = NULL;
    } else {
        while (temp->next != *tail)
            temp = temp->next;
        temp->next = (*tail)->next;
        free(*tail);
        *tail = temp;
    }
}

// Delete from position
void deleteAtPos(Node** tail, int pos) {
    if (!*tail || pos <= 1) { // Delete from front if position <= 1 or invalid
        deleteFront(tail);
        return;
    }
    Node* temp = (*tail)->next;
    for (int i = 1; i < pos - 1 && temp->next != (*tail)->next; i++)
        temp = temp->next;
    if (temp->next == (*tail)->next) { // Invalid position
        printf("Position out of bounds.\n");
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == *tail) *tail = temp; // Update tail if last node deleted
    free(toDelete);
}

// Display list
void display(Node* tail) {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = tail->next;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Main function
int main() {
    Node* tail = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert at front\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from front\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(&tail, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&tail, data);
                break;
            case 3:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPos(&tail, pos, data);
                break;
            case 4:
                deleteFront(&tail);
                break;
            case 5:
                deleteEnd(&tail);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(&tail, pos);
                break;
            case 7:
                display(tail);
                break;
            case 8:
                printf("Exiting program.\n");
                while (tail) deleteFront(&tail); // Free memory
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
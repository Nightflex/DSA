#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert();  // Declaration of insert function
void delete();  // Declaration of delete function
void display(); // Declaration of display function

int main() {
    int ch;
    while(1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;  // Return statement added to main
}

void insert() {
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));  // Memory allocation
    
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data to insert: ");
    scanf("%d", &temp->data);
    
    temp->link = NULL;  // Link the new node to NULL
    if (front == NULL && rear == NULL) {
        // If the queue is empty
        front = rear = temp;
    } else {
        // If the queue is not empty
        rear->link = temp;
        rear = temp;
    }
}

void delete() {
    struct node *temp;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    temp = front;
    printf("Element deleted is: %d\n", temp->data);
    front = front->link;
    
    if (front == NULL) {
        rear = NULL;  // If the queue is empty after deletion
    }
    
    free(temp);  // Free the memory of the deleted node
}

void display() {
    struct node *temp;
    if (front == NULL && rear == NULL) {
        printf("No elements in the queue\n");
        return;
    }
    
    temp = front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
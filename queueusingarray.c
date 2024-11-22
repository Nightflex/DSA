#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue functions
void enqueue(int queue[], int *front, int *rear, int value);
int dequeue(int queue[], int *front, int *rear);
void display(int queue[], int front, int rear);

int main() {
    int queue[MAX]; // Queue array
    int front = -1, rear = -1; // Initialize front and rear
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, &front, &rear, value);
                break;
            case 2:
                value = dequeue(queue, &front, &rear);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(int queue[], int *front, int *rear, int value) {
    if (*rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = *rear + 1;
    queue[*rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    int value = queue[*front];
    *front = *front + 1;

    // Reset front and rear when queue is empty
    if (*front > *rear) {
        *front = *rear = -1;
    }
    return value;
}

// Function to display the queue
void display(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) front = rear = -1;  // Queue is empty now
        else front = (front + 1) % MAX;
        return value;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) printf("%d dequeued\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function prototypes
void push(int value);
int pop();
int peek();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Top of stack: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed onto stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow! No elements to pop.\n");
        return -1;
    }
    return stack[top--];
}

// Function to get the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return stack[top];
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

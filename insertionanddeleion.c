#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the array

void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int arr[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array overflow, cannot insert element.\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    (*size)++;
    printf("Inserted %d at the beginning.\n", element);
}

void insertAtEnd(int arr[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array overflow, cannot insert element.\n");
        return;
    }
    arr[*size] = element;
    (*size)++;
    printf("Inserted %d at the end.\n", element);
}

void insertAtPosition(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array overflow, cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    printf("Inserted %d at position %d.\n", element, position);
}

void deleteAtBeginning(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array underflow, cannot delete element.\n");
        return;
    }
    printf("Deleted %d from the beginning.\n", arr[0]);
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteAtEnd(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array underflow, cannot delete element.\n");
        return;
    }
    printf("Deleted %d from the end.\n", arr[*size - 1]);
    (*size)--;
}

void deleteAtPosition(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array underflow, cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    printf("Deleted %d from position %d.\n", arr[position], position);
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current size of the array
    int choice, element, position;

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAtBeginning(arr, &size, element);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAtEnd(arr, &size, element);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, element, position);
                break;
            case 4:
                deleteAtBeginning(arr, &size);
                break;
            case 5:
                deleteAtEnd(arr, &size);
                break;
            case 6:
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                deleteAtPosition(arr, &size, position);
                break;
            case 7:
                display(arr, size);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

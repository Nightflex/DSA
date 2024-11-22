#include <stdio.h>

// Function Prototypes
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int n, int target);
void displayArray(int arr[], int n);

int main() {
    int arr[100], n, choice, target, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("1. Bubble Sort\n");
        printf("2. Binary Search\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Array sorted successfully.\n");
                break;

            case 2:
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                result = binarySearch(arr, n, target);
                if (result != -1)
                    printf("Element found at index %d \n", result);
                else
                    printf("Element not found in the array.\n");
                break;

            case 3:
                printf("Array elements: ");
                displayArray(arr, n);
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int i;
    printf("Array sorted successfully using bubbles Sort.\n");
    for(i=0;i<n;i++)
    {
     printf("%d \t",arr[i]);
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid; // Element found
        else if (arr[mid] < target)
            low = mid + 1; // Search the right half
        else
            high = mid - 1; // Search the left half
    }

    return -1; // Element not found
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

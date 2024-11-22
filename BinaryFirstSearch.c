#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void main() {
    int i, j, front = 0, rear = 0;
    int visited[MAX] = {0};  // Array to track visited nodes
    int queue[MAX] = {-1};   // Queue for BFS
    int u;                   // Current node being processed

    // Adjacency matrix for the graph
    int a[7][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 0, 0}
    };

    // Start BFS from node 0
    queue[rear++] = 0;
    visited[0] = 1;

    printf("Breadth-First Search: ");

    // BFS logic
    while (front < rear) {
        u = queue[front++];  // Dequeue
        printf("%d ", u);

        // Explore all adjacent nodes
        for (j = 0; j < 7; j++) {
            if (a[u][j] == 1 && visited[j] == 0) {
                queue[rear++] = j;  // Enqueue unvisited node
                visited[j] = 1;     // Mark as visited
            }
        }
    }
    printf("\n");
}
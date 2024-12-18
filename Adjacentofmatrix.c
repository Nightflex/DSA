#include <stdio.h>

#define MAX 100 // Define maximum number of vertices

void main() {
    int adj[MAX][MAX]; // Adjacency matrix
    int vertices, edges;
    int i, j;

    // Initialize the adjacency matrix with 0s
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges and create the adjacency matrix
    for(i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        // Since it's an undirected graph, mark both pairs
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

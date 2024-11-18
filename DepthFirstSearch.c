#include <stdio.h>
#define MAX 10

int main() {
    int n = 7, visited[MAX] = {0}, stack[MAX], top = -1;
    int graph[MAX][MAX] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 0, 0}
    };

    stack[++top] = 0; visited[0] = 1;  // Start DFS from node 0
    printf("DFS: 0 ");

    while (top >= 0) {
        int u = stack[top], found = 0;
        for (int i = 0; i < n; i++) {
            if (graph[u][i] == 1 && !visited[i]) {
                stack[++top] = i; visited[i] = 1; printf("%d ", i);
                found = 1; break;
            }
        }
        if (!found) top--;  // Backtrack
    }

    printf("\n");
    return 0;
}


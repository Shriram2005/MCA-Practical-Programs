/*
Question 8:
Write a program to create graph, use the map of your city as the graph. Represent graph using adjacency list/adjacency matrix and perform Depth First Search and Breadth First Search.
*/

#include <stdio.h>
int adj[10][10], visited[10], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
        if (adj[v][i] == 1 && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int q[20], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("\nDFS: ");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    dfs(start);

    printf("\nBFS: ");
    bfs(start);

    return 0;
}



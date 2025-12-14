#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int start) {
    int q[MAX], front = 0, rear = -1;
    int i, v;
    for (i = 0; i < n; i++) visited[i] = 0;
    visited[start] = 1;
    q[++rear] = start;
    while (front <= rear) {
        v = q[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    }
}

int main() {
    int i, j, e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    for (i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Enter start vertex for DFS and BFS: ");
    scanf("%d", &start);
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfs(start);
    printf("\nBFS: ");
    bfs(start);
    printf("\n");
    return 0;
}

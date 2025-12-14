#include <stdio.h>

#define INF 9999
#define MAX 20

int n;
int graph[MAX][MAX];

void dijkstra(int src) {
    int dist[MAX], visited[MAX], parent[MAX];
    int i, count, u, v, min;
    for (i = 0; i < n; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
        parent[i] = src;
    }
    dist[src] = 0;
    visited[src] = 1;

    for (count = 1; count < n - 1; count++) {
        min = INF; u = -1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i]; u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, src;
    printf("Enter number of areas (vertices): ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (enter %d for no edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter your home vertex (source): ");
    scanf("%d", &src);
    dijkstra(src);
    return 0;
}

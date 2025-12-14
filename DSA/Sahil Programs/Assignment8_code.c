/*
Question 9:
Write a program to represent a graph of your city using adjacency matrix /adjacency list. Nodes should represent the various areas in the city and links should represent the distance between them. Find the shortest path of your college from your home using Dijkstra's algorithm
*/

#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, src;
    int cost[10][10], dist[10], visited[10];
    int u = 0, v, min;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (999 for no path):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source city: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    visited[src] = 1;
    dist[src] = 0;

    for (i = 1; i < n; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distance from city %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}




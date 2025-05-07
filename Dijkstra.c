#include <stdio.h>
#define INF 9999
#define MAX 20

int minimum(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int adj[MAX][MAX], int n, int start, int dist[]) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minimum(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {
    int i, j, n, start;
    int adj[MAX][MAX], dist[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge, positive weights otherwise):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(adj, n, start, dist);

    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To vertex %d: INF (unreachable)\n", i);
        else
            printf("To vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define V 5
#define INF INT_MAX

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V] = {0};

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 1, 2},
        {20, 5, 0, 9, 0},
        {0, 1, 9, 0, 3},
        {0, 2, 0, 3, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

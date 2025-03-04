#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskal(Edge edges[], int n, int e) {
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    qsort(edges, e, sizeof(Edge), compareEdges);

    printf("Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
            unionSets(parent, x, y);
        }
    }
}

int main() {
    int n = 4, e = 5;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    kruskal(edges, n, e);

    return 0;
}

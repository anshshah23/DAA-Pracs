#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
#define MAX_VERTICES 100
#define MAX_EDGES 100

int num_vertices, num_edges;
int edges[MAX_EDGES][3];
int distance[MAX_VERTICES];

void bellmanFord(int src) {
    for (int i = 0; i < num_vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
    for (int i = 0; i < num_vertices - 1; i++) {
        for (int j = 0; j < num_edges; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
            printf("Graph contains negative cycle\n");
            return;
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &num_vertices, &num_edges);

    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(source);

    return 0;
}

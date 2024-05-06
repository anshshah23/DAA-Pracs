#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

int num_vertices, num_edges;
int edges[MAX_EDGES][3];
int distances[MAX_VERTICES];

void bellmanFord(int src) {
    // Initialize distances
    for (int i = 0; i < num_vertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < num_vertices - 1; i++) {
        for (int j = 0; j < num_edges; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            printf("Graph contains negative cycle\n");
            return;
        }
    }

    // Print distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
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

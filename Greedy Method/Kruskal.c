#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Define the maximum number of vertices
#define V 9

// A utility function to find the subset of an element 'i'
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int rank[], int x, int y) {
    int xparent = find(parent, x);
    int yparent = find(parent, y);

    if (rank[xparent] < rank[yparent])
        parent[xparent] = yparent;
    else if (rank[xparent] > rank[yparent])
        parent[yparent] = xparent;
    else {
        parent[yparent] = xparent;
        rank[xparent]++;
    }
}

// A utility function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(int graph[V][V]) {
    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0;
    int edgeCount = 0;
    int minCost = 0;

    while (edges < V - 1 && edgeCount < V * V) {
        int min = INT_MAX;
        int u, v;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(parent, i) != find(parent, j) && graph[i][j] < min) {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
                edgeCount++;
            }
        }

        Union(parent, rank, u, v);
        printf("Edge %d: %d-%d, Weight: %d\n", edges++, u, v, min);
        minCost += min;
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

// Driver function
int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    kruskalMST(graph);

    return 0;
}

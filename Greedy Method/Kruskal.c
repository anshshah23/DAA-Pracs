#include <stdio.h>
#include <stdlib.h>

// Comparator function to use in sorting 
int comparator(const void* p1, const void* p2) 
{ 
	const int(*x)[3] = p1; // Pointer to array of 3 integers
	const int(*y)[3] = p2; 

	return (*x)[2] - (*y)[2]; // Compare based on the third element
} 

// Initialization of parent[] and rank[] arrays 
void makeSet(int parent[], int rank[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		parent[i] = i; // Each element is its own parent initially
		rank[i] = 0; // Initially, each element's rank is 0
	} 
} 

// Function to find the parent of a node 
int findParent(int parent[], int component) 
{ 
	if (parent[component] == component) // If the parent of 'component' is 'component'
		return component; // Return 'component' itself

	// Otherwise, recursively find the parent of the parent of 'component'
	return parent[component] = findParent(parent, parent[component]); 
} 

// Function to unite two sets 
void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
	// Finding the parents 
	u = findParent(parent, u); // Find the representative of the set containing 'u'
	v = findParent(parent, v); // Find the representative of the set containing 'v'

	// Attach the smaller rank tree under the root of the higher rank tree
	if (rank[u] < rank[v]) { 
		parent[u] = v; 
	} 
	else if (rank[u] > rank[v]) { 
		parent[v] = u; 
	} 
	else { 
		parent[v] = u; // Arbitrary choice to attach 'v' under 'u'

		// Since the rank increases if the ranks of two sets are same 
		rank[u]++; // Increment the rank of 'u' since it now has another child
	} 
} 

// Function to find the MST 
void kruskalAlgo(int n, int edge[n][3]) 
{ 
	// First we sort the edge array in ascending order so that we can access minimum distances/cost 
	qsort(edge, n, sizeof(edge[0]), comparator); 

	int parent[n]; // Array to store the parent of each vertex
	int rank[n]; // Array to store the rank of each vertex (initially all 0)

	// Function to initialize parent[] and rank[]
	makeSet(parent, rank, n); 

	// To store the minimum cost 
	int minCost = 0; 

	printf("Following are the edges in the constructed MST\n"); 
	for (int i = 0; i < n; i++) { 
		int v1 = findParent(parent, edge[i][0]); // Find the representative of the set containing edge[i][0]
		int v2 = findParent(parent, edge[i][1]); // Find the representative of the set containing edge[i][1]
		int wt = edge[i][2]; // Weight of the current edge

		// If the parents are different, they are in different sets, so union them 
		if (v1 != v2) { 
			unionSet(v1, v2, parent, rank, n); // Union the sets containing v1 and v2
			minCost += wt; // Add the weight of the current edge to the minimum cost
			printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt); // Print the current edge
		} 
	} 

	printf("Minimum Cost Spanning Tree: %d\n", minCost); // Print the total weight of the minimum spanning tree
} 

// Driver code 
int main() 
{ 
	// Array representing the edges of the graph and their weights
	int edge[5][3] = { { 0, 1, 10 }, 
					   { 0, 2, 6 }, 
					   { 0, 3, 5 }, 
					   { 1, 3, 15 }, 
					   { 2, 3, 4 } }; 

	// Function call to find the minimum spanning tree using Kruskal's algorithm
	kruskalAlgo(5, edge); 

	return 0; // Indicate successful completion
}

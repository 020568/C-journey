#include <stdio.h>
#include <stdlib.h>

#define INF 1e8

/**
 * Floyd-Warshall algorithm to find all-pairs shortest paths
 * @param V: Number of vertices
 * @param dist: 2D array representing the adjacency matrix/distance table
 */
void floydWarshall(int V, int dist[V][V]) {
    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        // i is the source vertex
        for (int i = 0; i < V; i++) {
            // j is the destination vertex
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

/**
 * Helper function to print the distance matrix
 */
void printSolution(int V, int dist[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s ", "INF");
            else
                printf("%7d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    
    // Initial distance matrix based on the graph edges
    int dist[5][5] = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    // Execute the algorithm
    floydWarshall(V, dist);

    // Print the final shortest distance matrix
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    printSolution(V, dist);

    return 0;
}
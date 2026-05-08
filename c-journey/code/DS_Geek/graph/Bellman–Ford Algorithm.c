#include <stdio.h>
#include <stdlib.h>

#define INF 1e8

/**
 * Bellman-Ford algorithm to find shortest paths from src
 * Also detects negative weight cycles.
 * @param V: Number of vertices
 * @param E: Number of edges
 * @param edges: Array of edges {u, v, wt}
 * @param src: Source vertex
 */
void bellmanFord(int V, int E, int edges[][3], int src) {
    int* dist = (int*)malloc(V * sizeof(int));
    
    // Initialize distances from src to all other vertices as infinite
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    // Relax all edges V times. 
    // The first V-1 times are for shortest path calculation.
    // The Vth time is for negative cycle detection.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                // If we can still relax in the Vth iteration, 
                // it means a negative cycle exists.
                if (i == V - 1) {
                    printf("Graph contains negative weight cycle\n");
                    free(dist);
                    return;
                }
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Print the final distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    free(dist);
}

int main() {
    int V = 5;
    int E = 5;
    // Edge list: {source, destination, weight}
    int edges[5][3] = {
        {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Structure to represent a min heap node
struct MinHeapNode {
    int v;
    int dist;
};

// Structure to represent a min heap
struct MinHeap {
    int size;
    int capacity;
    int* pos; // To keep track of node positions for decreaseKey (optional but useful)
    struct MinHeapNode** array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to create a min heap node
struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// Standard minHeapify function
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];
        minHeap->array[smallest] = idxNode;
        minHeap->array[idx] = smallestNode;
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

// Function to insert/update distance in min heap
void push(struct MinHeap* minHeap, int v, int dist) {
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = newMinHeapNode(v, dist);

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        struct MinHeapNode* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// The main Dijkstra function
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->array = (struct MinHeapNode**)malloc(V * V * sizeof(struct MinHeapNode*)); // Large enough for simplicity
    minHeap->size = 0;

    for (int v = 0; v < V; ++v) dist[v] = INT_MAX;

    dist[src] = 0;
    push(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        int d = minHeapNode->dist;
        free(minHeapNode);

        // If current distance is not the latest shortest, skip it
        if (d > dist[u]) continue;

        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                push(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // Print the calculated shortest distances
    for (int i = 0; i < V; ++i) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 8);
    addEdge(graph, 1, 4, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 10);

    dijkstra(graph, 0);

    return 0;
}
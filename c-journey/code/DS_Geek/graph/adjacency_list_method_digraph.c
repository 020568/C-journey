#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 核心区别在此：添加边时只操作起点 u
void addDirectedEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

int main() {
    int V = 3;
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjLists = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adjLists[i] = NULL;

    // 对应 C++ 中的 edges
    addDirectedEdge(graph, 1, 0);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 0);

    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);
        while (temp) 
		{
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}
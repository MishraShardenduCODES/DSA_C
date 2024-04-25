#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph->vertices[i][j] = 0;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->vertices[src][dest] = 1;
}

void dfsUtil(Graph* graph, int vertex, int visited[]) {
    printf("%c ", vertex + 'A');
    visited[vertex] = 1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[vertex][i] && !visited[i])
            dfsUtil(graph, i, visited);
    }
}

void dfs(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal order: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i])
            dfsUtil(graph, i, visited);
    }
}

int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    dfs(graph);

    return 0;
}

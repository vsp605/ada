#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  
} Graph;
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph* g, int u, int v) {
    g->adjMatrix[u][v] = 1;  
    g->adjMatrix[v][u] = 1;
}
void DFS(Graph* g, int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS(g, visited, i);
        }
    }
}
int main() {
    Graph g;
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u, v) where u and v are the vertex indices (0 to %d):\n", vertices - 1);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }
    int visited[MAX_VERTICES] = {0}; 
    printf("DFS Traversal starting from vertex 0:\n");
    DFS(&g, visited, 0);
    printf("\n");
    return 0;
}


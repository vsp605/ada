#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int N;
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < N; i++) {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}
void dijkstra(int graph[N][N], int src) {
    int dist[N];       
    bool visited[N]; 
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < N - 1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printSolution(dist);
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    int graph[N][N], src;
    printf("Enter the adjacency matrix for the graph (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Mat[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source node (0 to %d): ", N - 1);
    scanf("%d", &src);
    dijkstra(graph, src);
    return 0;
}

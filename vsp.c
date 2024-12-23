#include <stdio.h>

#define MAX_VERTICES 10

int parent[MAX_VERTICES], n, cost[MAX_VERTICES][MAX_VERTICES];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal() {
    int mincost = 0, ne = 0;
    printf("\nEdges in the minimum spanning tree:\n");
    
    while (ne < n - 1) {
        int min = 999, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            union_sets(a, b);
            printf("Edge %d: (%d - %d) cost: %d\n", ne + 1, a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Mat[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999; // Replace 0 with a large value
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i; // Initialize parent array

    kruskal();
    return 0;
}

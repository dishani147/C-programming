#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;
  
    // Initialize the solution matrix with the same values as the input graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
  
    // Find the shortest path between all pairs of vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF
                    && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
  
    // Print the shortest distances
    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
  
    floydWarshall(graph);
  
    return 0;
}
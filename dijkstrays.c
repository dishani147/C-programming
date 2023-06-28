#include <stdio.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX_SIZE 100

void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int source, int vertices)
{
    int dist[MAX_SIZE];
    bool visited[MAX_SIZE];
    
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INFINITY;
        visited[i] = false;
    }
    
    dist[source] = 0;
    
    for (int count = 0; count < vertices - 1; count++)
    {
        int u = -1;
        
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        }
        
        visited[u] = true;
        
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    
    printf("Vertex\tDistance\n");
    for (int i = 0; i < vertices; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver program to test the above function
int main()
{
    int graph[MAX_SIZE][MAX_SIZE] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };
    
    int vertices = 5;
    int source = 0;
    
    dijkstra(graph, source, vertices);
    
    return 0;
}

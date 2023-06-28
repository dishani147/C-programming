#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices;


int isSafe(int v, int color, int vertexColor[]) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && vertexColor[i] == color)
            return 0;
    }
    return 1;
}


int graphColoringUtil(int vertexColor[], int v) {
    if (v == numVertices)
        return 1;

    for (int color = 1; color <= numVertices; color++) {
        if (isSafe(v, color, vertexColor)) {
            vertexColor[v] = color;

            if (graphColoringUtil(vertexColor, v + 1))
                return 1;

            vertexColor[v] = 0; 
        }
    }
    return 0;
}


void graphColoring() {
    int vertexColor[MAX_VERTICES] = {0}; 

    if (graphColoringUtil(vertexColor, 0)) {
        printf("Graph can be colored with at most %d colors.\n", numVertices);
        printf("Coloring scheme:\n");
        for (int i = 0; i < numVertices; i++)
            printf("Vertex %d: Color %d\n", i + 1, vertexColor[i]);
    } else {
        printf("Graph cannot be colored with %d colors.\n", numVertices);
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring();
    /*
    4
    1 1 1 1
    1 0 1 0
    1 1 0 1
    0 0 1 1
    */

    return 0;
}
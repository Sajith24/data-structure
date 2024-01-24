#include <stdio.h> 
#include <stdlib.h> 

#define MAX_VERTICES 100 
#define MAX_EDGES 100 

struct Edge { 
    int src, dest, weight; 
}; 

struct Graph { 
    int vertices, edges; 
    struct Edge* edge; 
}; 

struct Subset { 
    int parent, rank; 
}; 

struct Graph* createGraph(int vertices, int edges); 
int find(struct Subset subsets[], int i); 
void Union(struct Subset subsets[], int x, int y); 
int compareEdges(const void* a, const void* b); 
void kruskalMST(struct Graph* graph); 

int main() { 
    int vertices, edges; 

    printf("Enter the number of vertices in the graph: "); 
    scanf("%d", &vertices); 

    printf("Enter the number of edges in the graph: "); 
    scanf("%d", &edges); 

    struct Graph* graph = createGraph(vertices, edges); 

    printf("Enter the edges (source destination weight):\n"); 
    for (int i = 0; i < edges; ++i) { 
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight); 
    } 

    kruskalMST(graph); 

    free(graph->edge); 
    free(graph); 

    return 0; 
} 

struct Graph* createGraph(int vertices, int edges) { 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->vertices = vertices; 
    graph->edges = edges; 
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge)); 
    return graph; 
} 

int find(struct Subset subsets[], int i) { 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 

void Union(struct Subset subsets[], int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 

    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 

int compareEdges(const void* a, const void* b) { 
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight; 
} 

void kruskalMST(struct Graph* graph) { 
    int vertices = graph->vertices; 
    struct Edge result[vertices]; 
    int e = 0; 
    int i = 0; 

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges); 

    struct Subset* subsets = (struct Subset*)malloc(vertices * sizeof(struct Subset)); 

    for (int v = 0; v < vertices; ++v) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 

    while (e < vertices - 1 && i < graph->edges) { 
        struct Edge nextEdge = graph->edge[i++]; 

        int x = find(subsets, nextEdge.src); 
        int y = find(subsets, nextEdge.dest); 

        if (x != y) { 
            result[e++] = nextEdge; 
            Union(subsets, x, y); 
        } 
    } 

    printf("Edges in MST:\n"); 
    for (i = 0; i < e; ++i) 
        printf("%d -- %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight); 

    free(subsets); 
} 
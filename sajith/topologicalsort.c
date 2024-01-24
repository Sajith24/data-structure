#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    
    for (int i = 0; i < vertices; ++i)
        graph->adjacencyList[i] = NULL;

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
   
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}


struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}


void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}


void topologicalSortUtil(struct Graph* graph, int vertex, int* visited, struct Stack* stack) {
    visited[vertex] = 1;

        struct Node* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        if (!visited[current->data])
            topologicalSortUtil(graph, current->data, visited, stack);
        current = current->next;
    }


    push(stack, vertex);
}
void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    struct Stack* stack = createStack(graph->vertices);


    for (int i = 0; i < graph->vertices; ++i)
        visited[i] = 0;
    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack);
    }


    printf("Topological Sort: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }


    free(visited);
    free(stack->array);
    free(stack);
}


int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

  
    topologicalSort(graph);

  
    free(graph);

    return 0;
}

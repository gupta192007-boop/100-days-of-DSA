/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100


struct Node {
    int vertex;
    int weight;
    struct Node* next;
};


struct Graph {
    int V;
    struct Node* adj[MAX];
};


struct HeapNode {
    int vertex;
    int dist;
};


struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}


void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}


void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}



void heapify(struct HeapNode heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < n && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}


struct HeapNode extractMin(struct HeapNode heap[], int *size) {
    struct HeapNode root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    heapify(heap, *size, 0);
    return root;
}


void decreaseKey(struct HeapNode heap[], int size, int v, int dist) {
    for (int i = 0; i < size; i++) {
        if (heap[i].vertex == v) {
            heap[i].dist = dist;

            // Fix heap
            while (i > 0 && heap[i].dist < heap[(i-1)/2].dist) {
                swap(&heap[i], &heap[(i-1)/2]);
                i = (i-1)/2;
            }
            break;
        }
    }
}

// Dijkstra function
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;

    int dist[MAX];
    struct HeapNode heap[MAX];
    int size = V;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        heap[i].vertex = i;
        heap[i].dist = INT_MAX;
    }


    dist[src] = 0;
    heap[src].dist = 0;

    
    for (int i = V/2 - 1; i >= 0; i--)
        heapify(heap, V, i);

    while (size > 0) {
        struct HeapNode minNode = extractMin(heap, &size);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                decreaseKey(heap, size, v, dist[v]);
            }
            temp = temp->next;
        }
    }


    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 4, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 4, 7);

    dijkstra(graph, 0);

    return 0;
}
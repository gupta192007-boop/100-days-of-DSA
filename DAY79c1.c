#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100


typedef struct Node {
    int v, w;
    struct Node* next;
} Node;


Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}


typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;


void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}


void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}


void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}


HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}


void dijkstra(int n, Node* adj[], int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode top = pop();
        int u = top.node;

        Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }


    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[MAX] = {NULL};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}
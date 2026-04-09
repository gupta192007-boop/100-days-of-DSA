/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;


void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, m;
    int adj[MAX][MAX] = {0};  
    int indegree[MAX] = {0};
    int i, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;   // increase indegree
    }

    // Step 1: Push nodes with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    int count = 0;

    // Step 2: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // reduce indegree of neighbors
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 3: Check cycle
    if (count != n)
        printf("\nCycle exists! Topological sort not possible.\n");

    return 0;
}
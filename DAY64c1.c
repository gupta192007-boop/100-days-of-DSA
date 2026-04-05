#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   
int visited[MAX];      
int q[MAX];            

int front = -1, rear = -1;

void push(int value) {
    if (front == -1) front = 0;
    q[++rear] = value;
}

int pop() {
    int value = q[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}

// BFS function
void bfs(int n, int start) {
    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    push(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != -1) {
        int current = pop();
        printf("%d ", current);
  
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    bfs(n, start);

    return 0;
}
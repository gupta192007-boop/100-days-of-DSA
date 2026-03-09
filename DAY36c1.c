#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int size;

void enqueue(int value)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;
    queue[rear] = value;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void display()
{
    if (front == -1)
        return;

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    size = n;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}
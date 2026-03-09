#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size] = x;
    size++;
}

int findMinIndex()
{
    if (size == 0)
        return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (pq[i] < pq[minIndex])
            minIndex = i;
    }

    return minIndex;
}

void delete()
{
    int minIndex = findMinIndex();

    if (minIndex == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

void peek()
{
    int minIndex = findMinIndex();

    if (minIndex == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);
}

int main()
{
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0)
        {
            delete();
        }
        else if (strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}
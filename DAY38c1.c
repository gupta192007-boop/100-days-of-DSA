/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if(front == 0)
        printf("Overflow\n");
    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void push_back(int x)
{
    if(rear == MAX-1)
        printf("Overflow\n");
    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void pop_front()
{
    if(front == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(front == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void display()
{
    if(front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Deque elements:\n");
    display();

    pop_front();
    pop_back();

    printf("After deletions:\n");
    display();

    return 0;
}
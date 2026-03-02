/* Problem : Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}


struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp = NULL, *newNode = NULL;

    //List1
    scanf("%d", &n);

    int arr1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    for (int i = 0; i < n; i++) {
        newNode = createNode(arr1[i]);
        if (head1 == NULL)
            head1 = newNode;
        else {
            temp = head1;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    //List2
    scanf("%d", &m);

    int arr2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    
    struct Node* intersection = NULL;

    for (int i = 0; i < m; i++) {
        
        struct Node* check = head1;
        while (check != NULL) {
            if (check->data == arr2[i]) {
                intersection = check;
                break;
            }
            check = check->next;
        }

        if (intersection != NULL) {
            if (head2 == NULL)
                head2 = intersection;
            else {
                temp = head2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = intersection;
            }
            break;
        }

        newNode = createNode(arr2[i]);
        if (head2 == NULL)
            head2 = newNode;
        else {
            temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    struct Node* result = getIntersectionNode(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}
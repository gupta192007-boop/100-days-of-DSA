/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n)
                nodes[i]->left = nodes[leftIndex];
            if(rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];
}


int isMirror(struct Node* t1, struct Node* t2) {
    if(t1 == NULL && t2 == NULL) return 1;
    if(t1 == NULL || t2 == NULL) return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}


int isSymmetric(struct Node* root) {
    if(root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    if(isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
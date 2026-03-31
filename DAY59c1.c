/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


int find(int in[], int s, int e, int x) {
    for (int i = s; i <= e; i++) {
        if (in[i] == x)
            return i;
    }
    return -1;
}

// Build tree
struct Node* makeTree(int in[], int post[], int s, int e, int* p) {
    if (s > e)
        return NULL;

    int x = post[*p];  
    (*p)--;

    struct Node* root = newNode(x);

    int pos = find(in, s, e, x);

    
    root->right = makeTree(in, post, pos + 1, e, p);
    root->left  = makeTree(in, post, s, pos - 1, p);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int in[n], post[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    int p = n - 1;

    struct Node* root = makeTree(in, post, 0, n - 1, &p);

    preorder(root);

    return 0;
}
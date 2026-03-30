#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(curr);

    
    if (start == end)
        return root;

    
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == curr)
            break;
    }

    
    root->left = buildTree(preorder, inorder, start, i - 1, preIndex);
    root->right = buildTree(preorder, inorder, i + 1, end, preIndex);

    return root;
}


void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
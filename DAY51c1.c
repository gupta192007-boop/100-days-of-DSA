#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->val && q < root->val)
        return LCA(root->left, p, q);

    if (p > root->val && q > root->val)
        return LCA(root->right, p, q);

    return root; 
}

int main() {
    int n;
    scanf("%d", &n);

    int val;
    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->val);

    return 0;
}
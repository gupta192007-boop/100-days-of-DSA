/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


int countLeafNodes(struct TreeNode* root) {
    
    if (root == NULL)
        return 0;

    
    if (root->left == NULL && root->right == NULL)
        return 1;

    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
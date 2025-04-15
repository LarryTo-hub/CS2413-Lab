/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;             // Visit the root
    traverse(root->left, result, index);        // Traverse left
    traverse(root->right, result, index);       // Traverse right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(100 * sizeof(int));  // Allocate space for result
    *returnSize = 0;                                // Initialize return size
    traverse(root, result, returnSize);             // Perform preorder traversal
    return result;
}


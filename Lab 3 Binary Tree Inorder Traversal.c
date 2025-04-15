/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to perform recursive inorder traversal
void traverse(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    traverse(root->left, result, index);         // Visit left subtree
    result[(*index)++] = root->val;              // Visit root
    traverse(root->right, result, index);        // Visit right subtree
}

// Main function called by LeetCode
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 100);  // Allocate space for result array
    *returnSize = 0;                                // Initialize output size
    traverse(root, result, returnSize);             // Perform traversal
    return result;
}

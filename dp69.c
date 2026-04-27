#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    // Empty tree
    if (root == NULL)
        return 0;

    // If node has no children, it is a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Count in left + right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Example tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("%d\n", countLeafNodes(root));

    return 0;
}
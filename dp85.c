#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int postIndex;

// Find root index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree using inorder and postorder
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    // Last element in postorder is root
    int rootValue = postorder[postIndex--];
    struct Node* root = createNode(rootValue);

    // If leaf node
    if (start == end)
        return root;

    // Find root in inorder
    int inIndex = search(inorder, start, end, rootValue);

    // Important: build right subtree first
    root->right = buildTree(inorder, postorder, inIndex + 1, end);
    root->left = buildTree(inorder, postorder, start, inIndex - 1);

    return root;
}

// Print preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    postIndex = N - 1;

    struct Node* root = buildTree(inorder, postorder, 0, N - 1);

    preorder(root);

    return 0;
}
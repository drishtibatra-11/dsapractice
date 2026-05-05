#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    int vertical[MAX][MAX];
    int count[MAX] = {0};

    struct QueueNode queue[MAX];
    int front = 0, rear = 0;

    int offset = MAX / 2;

    queue[rear++] = (struct QueueNode){root, offset};

    int min = offset, max = offset;

    while (front < rear) {
        struct QueueNode temp = queue[front++];

        struct Node* curr = temp.node;
        int hd = temp.hd;

        vertical[hd][count[hd]++] = curr->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (curr->left)
            queue[rear++] = (struct QueueNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QueueNode){curr->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", vertical[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
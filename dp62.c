#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue for storing node pointers
typedef struct {
    Node* arr[MAX];
    int front, rear;
} Queue;

// Queue functions
void enqueue(Queue *q, Node* node) {
    q->arr[++(q->rear)] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[(q->front)++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

// Create new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    Queue q;
    q.front = 0;
    q.rear = -1;

    Node* root = createNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while(i < n) {
        Node* current = dequeue(&q);

        // Left child
        if(i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // Right child
        if(i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}
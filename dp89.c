#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add edge in adjacency list
void addEdge(struct Node* adj[], int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void DFS(int vertex, struct Node* adj[], int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = adj[vertex];

    while(temp != NULL)
    {
        int connectedVertex = temp->data;

        if(visited[connectedVertex] == 0)
        {
            DFS(connectedVertex, adj, visited);
        }

        temp = temp->next;
    }
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize adjacency list
    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }

    // Input edges
    printf("Enter edges:\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // for undirected graph
    }

    int visited[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, adj, visited);

    return 0;
}
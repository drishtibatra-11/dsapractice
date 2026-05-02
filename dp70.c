#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>

#define MAX 100

int tree[MAX][MAX];
int degree[MAX];
int visited[MAX];
int leafCount = 0;

void dfs(int node, int parent) {
    visited[node] = 1;
    int children = 0;

    for (int i = 0; i < degree[node]; i++) {
        int child = tree[node][i];

        if (child != parent) {
            children++;
            dfs(child, node);
        }
    }

    // If no children, it is a leaf node
    if (children == 0) {
        leafCount++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Input n-1 edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        tree[u][degree[u]++] = v;
        tree[v][degree[v]++] = u;
    }

    // Start DFS from root node 1
    dfs(1, -1);

    printf("%d\n", leafCount);
=======

int graph[10][10], visited[10], n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }

    printf("DFS Traversal: ");
    DFS(0);
>>>>>>> c77cd67e11f91d86e202cfa3aa421eaf0a119b1f

    return 0;
}
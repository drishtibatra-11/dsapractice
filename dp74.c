#include <stdio.h>
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

    return 0;
}
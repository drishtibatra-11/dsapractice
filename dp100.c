#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000000

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* graph[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;

    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {

    Node* newNode = createNode(v, w);

    newNode->next = graph[u];
    graph[u] = newNode;
}

// Dijkstra Algorithm
void dijkstra(int n, int source) {

    int dist[MAX];
    int visited[MAX];

    // initialize
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // run n times
    for (int count = 1; count <= n; count++) {

        int u = -1;
        int minDist = INF;

        // find minimum distance vertex
        for (int i = 1; i <= n; i++) {

            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // no reachable node
        if (u == -1)
            break;

        visited[u] = 1;

        // relax edges
        Node* temp = graph[u];

        while (temp != NULL) {

            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 0; i < MAX; i++) {
        graph[i] = NULL;
    }

    // input edges
    for (int i = 0; i < m; i++) {

        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w); // undirected graph
    }

    int source;

    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
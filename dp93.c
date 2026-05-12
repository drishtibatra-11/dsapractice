#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int to;
    int weight;
    struct Edge* next;
};

// Graph
struct Edge* graph[MAX];

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Priority Queue
struct HeapNode heap[MAX];
int heapSize = 0;

// Distance array
int dist[MAX];

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into min heap
void push(int vertex, int distance) {

    heap[++heapSize].vertex = vertex;
    heap[heapSize].dist = distance;

    int i = heapSize;

    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

// Pop minimum node
struct HeapNode pop() {

    struct HeapNode minNode = heap[1];

    heap[1] = heap[heapSize--];

    int i = 1;

    while (1) {

        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= heapSize &&
            heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right <= heapSize &&
            heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else {
            break;
        }
    }

    return minNode;
}

// Add edge
void addEdge(int u, int v, int w) {

    struct Edge* newEdge =
        (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->to = v;
    newEdge->weight = w;
    newEdge->next = graph[u];

    graph[u] = newEdge;
}

// Dijkstra
void dijkstra(int V, int source) {

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    push(source, 0);

    while (heapSize > 0) {

        struct HeapNode current = pop();

        int u = current.vertex;
        int d = current.dist;

        // Skip outdated entries
        if (d > dist[u])
            continue;

        struct Edge* temp = graph[u];

        while (temp != NULL) {

            int v = temp->to;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {

                dist[v] = dist[u] + weight;

                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print shortest distances
    printf("Shortest distances from source %d:\n", source);

    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Main
int main() {

    int V = 5;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(4, 3, 2);
    addEdge(3, 2, 4);
    addEdge(2, 3, 6);

    dijkstra(V, 0);

    return 0;
}
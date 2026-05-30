#include <stdio.h>

#define V 5

void BFS(int graph[V][V], int start) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear) {
        int node = queue[front++];

        printf("%d ", node);

        for(int i = 0; i < V; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };

    BFS(graph, 0);

    return 0;
}
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int DFS(int current, int parent, int n)
{
    visited[current] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] == 1)
        {
            // If node not visited
            if (visited[i] == 0)
            {
                if (DFS(i, current, n))
                    return 1;
            }

            // If visited and not parent => cycle
            else if (i != parent)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int cycle = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (DFS(i, -1, n))
            {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
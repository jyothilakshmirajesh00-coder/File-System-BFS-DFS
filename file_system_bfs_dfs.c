#include <stdio.h>
#include <string.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
char files[MAX][30];
int n;

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%s ", files[v]);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%s ", files[v]);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

int main()
{
    int i, j, start, target;
    int found = 0;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    printf("Enter file/directory names:\n");

    for (i = 0; i < n; i++)
        scanf("%29s", files[i]);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter target node index (0 to %d): ", n - 1);
    scanf("%d", &target);

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    for (i = 0; i < n; i++)
        visited[i] = 0;

    /* Search the target using BFS */
    {
        int queue[MAX], front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = 1;

        while (front < rear)
        {
            int v = queue[front++];

            if (v == target)
            {
                found = 1;
                break;
            }

            for (i = 0; i < n; i++)
            {
                if (graph[v][i] && !visited[i])
                {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
    }

    if (found)
        printf("File/Directory '%s' is FOUND.\n", files[target]);
    else
        printf("File/Directory '%s' is NOT FOUND.\n", files[target]);

    return 0;
}

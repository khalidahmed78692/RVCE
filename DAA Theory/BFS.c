#include <stdio.h>
#include <stdbool.h>

int count = 0, nov;

void BFS(bool adj_mat[nov][nov], int nov, bool ver_mat[nov], int visited)
{
    int queue[nov], front = 0, rear = -1, node;
    ver_mat[visited] = true;
    queue[++rear] = visited;
    while (front <= rear)
    {
        node = queue[front++];
        for (int i = 0; i < nov; i++)
            if (adj_mat[node][i]==true && ver_mat[i]==false)
            {
                queue[++rear] = i;
                ver_mat[i] = true;
                printf("%d ", i + 1);
            }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &nov);
    bool adj_mat[nov][nov], ver_mat[nov];
    int i, j;
    printf("Enter the adjacency matrix( %d x %d elements):\n", nov, nov);
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            scanf("%d", &adj_mat[i][j]);
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    printf("BFS order is: ");
    for (i = 0; i < nov; i++)
    {
        if (!ver_mat[i])
        {
            printf("%d ", i + 1);
            BFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    }
    if (count == 1)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected and there are %d graph pieces", count);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

int count = 0, nov;

void DFS(bool adj_mat[nov][nov], int nov, bool ver_mat[nov], int vtd)
{
    ver_mat[vtd] = true;
    for (int i = 0; i < nov; i++)
    {
        if (adj_mat[vtd][i] && !ver_mat[i])
        {
            printf("%d ", i + 1);
            DFS(adj_mat, nov, ver_mat, i);
        }
    }
}

void BFS(bool adj_mat[nov][nov], int nov, bool ver_mat[nov], int vtd)
{
    int queue[nov], front = 0, rear = -1, node;
    ver_mat[vtd] = true;
    queue[++rear] = vtd;
    while (front <= rear)
    {
        node = queue[front++];
        for (int i = 0; i < nov; i++)
            if (adj_mat[node][i] && !ver_mat[i])
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
    printf("Enter the adjacency matrix (%d x %d elements):\n", nov, nov);
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            scanf("%d", &adj_mat[i][j]);
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    printf("\nDFS order is: ");
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            printf("%d ", i + 1);
            DFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    if (count == 0)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected and there are %d components of it", count);
    count = 0;
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    printf("\n\nBFS order is: ");
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            printf("%d ", i + 1);
            BFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    if (count == 0)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected and there are %d components of it", count);
    return 0;
}


/*

Output of the code:

Enter the number of vertices: 10
Enter adjacency matrix
0 0 1 1 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 1 0 0 0 1 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
DFS traversal is: 1 3 6 5 2 4 7 8 9 10


Enter the number of vertices: 7
Enter adjacency matrix
0 1 1 1 1 0 0
1 0 0 1 0 1 0
1 0 0 0 0 0 1
1 1 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0 
0 0 1 0 1 0 0
DFS traversal is: 1 2 4 6 3 7 5

*/

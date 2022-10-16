#include <stdio.h>
#include <stdbool.h>

int nov;

void ver_del(bool adj[nov][nov], int nov, int indeg[nov], int i)
{
    indeg[i] = -1;
    printf("%d ", i + 1);
    for (int j = 0; j < nov; j++)
        if (adj[i][j])
            indeg[j] = indeg[j] - 1;
}

int main()
{

    printf("Enter the number of vertices: ");
    scanf("%d", &nov);
    bool adj[nov][nov];
    int i, j, indeg[nov];
    for (i = 0; i < nov; i++)
        indeg[i] = 0;
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
        {
            scanf("%d", &adj[i][j]);
            // finding indegrees of all vertices
            if (adj[i][j])
                indeg[j]++;
        }
    printf("Initial indegrees: ");
    for (i = 0; i < nov; i++)
        printf("%d ", indeg[i]);
    printf("\nTopological sort is: ");
    for (i = 0; i < nov; i++)
    {
        if (i == nov)
            break;
        if (indeg[i] == 0)
        {
            ver_del(adj, nov, indeg, i);
            i = -1;
        }
    }
    return 0;
}

/*

Output of the code:



*/

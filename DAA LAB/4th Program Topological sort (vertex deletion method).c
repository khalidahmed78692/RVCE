#include <stdio.h>
#include <stdbool.h>

int nov;

void ver_del(bool adj[nov][nov], int indeg[nov], int i)
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
        if (indeg[i] == 0)
        {
            ver_del(adj, indeg, i);
            i = -1;
        }
    }
    return 0;
}

/*

Output of the code:

Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 0 1
0 0 0 1
0 0 0 0
0 0 1 0
Initial indegrees: 0 1 1 2
Topological sort is: 1 2 4 3



Enter the number of vertices: 7
Enter the adjacency matrix:
0 1 1 0 0 0 0
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 1 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 1 1 0
Initial indegrees: 1 2 2 0 2 3 2 
Topological sort is: 4 1 2 3 7 5 6

*/

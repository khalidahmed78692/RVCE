#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int n;

void prims(int wm[n][n], int n)
{
    int i, j, u, v, min, mincost = 0, ne = 1;
    bool visited[n];
    for (i = 1; i <= n; i++)
        visited[i] = false;
    visited[1] = true;
    printf("The MST edges are:\n");
    while (ne < n)
    {
        for (i = 1, min = INT_MAX; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (wm[i][j] < min)
                    if (!visited[i])
                        continue;
                    else
                    {
                        min = wm[i][j];
                        u = i;
                        v = j;
                    }
        if (!visited[u] || !visited[v])
        {
            printf("%d) Edges (%d,%d) = %d\n", ne++, u + 1, v + 1, min);
            mincost += min;
            visited[v] = true;
        }
        wm[u][v] = wm[v][u] = INT_MAX;
    }
    printf("The minimum cost of the MST is: %d", mincost);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int i, j, wgt_mat[n][n];
    printf("Enter the weighted matrix of %dx%d elements\n", n, n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &wgt_mat[i][j]);
            if (!wgt_mat[i][j])
                wgt_mat[i][j] = INT_MAX;
        }
    prims(wgt_mat, n);
    return 0;
}

/*

Output of the code:

Enter the number of vertices: 9
Enter 9x9=81 elements:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Edges included in the MST are:
1) Edge(1,2) = 4
2) Edge(1,8) = 8
3) Edge(8,7) = 1
4) Edge(7,6) = 2
5) Edge(6,3) = 4
6) Edge(3,9) = 2
7) Edge(3,4) = 7
8) Edge(4,5) = 9
Cost of constructing MST is: 37




Enter the number of vertices: 6
Enter the weighted matrix of 6x6 elements
0 3 0 0 5 6
3 0 1 0 4 0
0 1 0 6 4 0
0 0 6 0 5 3
5 4 4 5 0 2
6 0 0 3 2 0
The edges considered for MST are
1 Edge(1,2)=3
2 Edge(2,3)=1
3 Edge(2,5)=4
4 Edge(5,6)=2
5 Edge(6,4)=3
Cost of constructing MST is: 13

*/

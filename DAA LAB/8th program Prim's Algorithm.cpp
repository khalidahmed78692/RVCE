#include <iostream>
using namespace std;

void prims(int wm[10][10], int n)
{
    int i, j, u, v, min, mincost = 0, visited[10], ne = 1;
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    cout << "The edges considered for MST are\n";
    visited[1] = 1;
    while (ne < n)
    {
        for (i = 1, min = INT_MAX; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (wm[i][j] < min)
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = wm[i][j];
                        u = i;
                        v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0)
        {
            cout << ne++ << " Edge (" << u << "," << v << ") = " << min << endl;
            mincost += min;
            visited[v] = 1;
        }
        wm[u][v] = wm[v][u] = INT_MAX;
    }
    cout << "Cost of constructing MST is: " << mincost;
}

int main()
{
    int n, wei_mat[10][10], i, j;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the weighted matrix of " << n << "x" << n << " elements\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            cin >> wei_mat[i][j];
            if (!wei_mat[i][j])
                wei_mat[i][j] = INT_MAX;
        }
    prims(wei_mat, n);
}

/*

Output of the code:

Enter the number of vertices: 9
Enter the weighted matrix of 9x9 elements
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
The MST edges are:
1) Edges (0,1) = 4
2) Edges (0,7) = 8
3) Edges (7,6) = 1
4) Edges (6,5) = 2
5) Edges (5,2) = 4
6) Edges (2,8) = 2
7) Edges (2,3) = 7
8) Edges (3,4) = 9
The minimum cost of the MST is: 37



Enter the number of vertices: 6
Enter 6x6=36 elements:
0 3 0 0 5 6
3 0 1 0 4 0
0 1 0 6 4 0
0 0 6 0 5 3
5 4 4 5 0 2
6 0 0 3 2 0
Edges included in the MST are:
1) Edge(1,2) = 3
2) Edge(2,3) = 1
3) Edge(2,5) = 4
4) Edge(5,6) = 2
5) Edge(6,4) = 3
Cost of constructing MST is: 13

*/

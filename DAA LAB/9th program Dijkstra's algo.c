#include <stdio.h>
#include <stdbool.h>

void Dijkstras(int cost[10][10], int dist[10], int parent[10], int n, int s)
{
    bool visited[10];
    int i, v, min, count = 1;
    for (i = 1; i <= n; i++)
    {
        visited[i] = false;
        dist[i] = cost[s][i];
        if (dist[i] != 999)
            parent[i] = s;
    }
    parent[s] = -1;
    visited[s] = true;
    dist[s] = 0;
    while (count <= n)
    {
        for (i = 1, min = 999; i <= n; i++)
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                v = i;
            }
        visited[v] = true;
        count++;
        for (i = 1; i <= n; i++)
            if (!visited[i] && dist[i] > dist[v] + cost[v][i])
            {
                dist[i] = dist[v] + cost[v][i];
                parent[i] = v;
            }
    }
}

int main()
{
    int i, j, s, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int cost[10][10], dist[10], parent[10];
    printf("Enter the weighted matrix (%dx%d=%d):\n", n, n, n * n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (!cost[i][j])
                cost[i][j] = 999;
        }
    printf("Enter the sources vertex: ");
    scanf("%d", &s);
    Dijkstras(cost, dist, parent, n, s);
    printf("The shortest distances from %d to all other vertices are:", s);
    for (i = 1; i <= n; i++)
        if (s != i)
        {
            printf("\n%d---->%d is %d. Path is %d", s, i, dist[i], i);
            j = i;
            do
            {
                j = parent[j];
                printf("<---%d", j);
            } while (j != s);
        }
}


/*
Output of the code:

Enter the number of vertices: 4
Enter the weighted matrix (4x4=16):
0 10 3 20
0 0 0 5
0 2 0 3
0 0 0 0
Enter the sources vertex: 1
The shortest distances from 1 to all other vertices are:
1---->2 is 5. Path is 2<---3<---1
1---->3 is 3. Path is 3<---1
1---->4 is 6. Path is 4<---3<---1




Enter the number of vertices: 5
Enter the weighted matrix (5x5=25):
0 10 3 0 0
0 0 1 2 0
0 4 0 8 2
0 0 0 0 7
0 0 0 9 0
Enter the sources vertex: 1
The shortest distances from 1 to all other vertices are:
1---->2 is 7. Path is 2<---3<---1
1---->3 is 3. Path is 3<---1
1---->4 is 9. Path is 4<---2<---3<---1
1---->5 is 5. Path is 5<---3<---1
    
*/

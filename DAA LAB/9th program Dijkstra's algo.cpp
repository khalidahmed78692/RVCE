#include <iostream>
using namespace std;

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
    cout << "Enter the number of vertices: ";
    cin >> n;
    int cost[10][10], dist[10], parent[10];
    cout << "Enter the weighted matrix (" << n << "x" << n << "=" << n * n << " elements)\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (!cost[i][j])
                cost[i][j] = 999;
        }
    cout << "Enter the sources vertex: ";
    cin >> s;
    Dijkstras(cost, dist, parent, n, s);
    cout << "The shortest distances from " << s << " to all other vertices are:";
    for (i = 1; i <= n; i++)
        if (s != i)
        {
            cout << endl
                 << s << "---->" << i << " is " << dist[i] << " . Path is " << i;
            j = i;
            do
            {
                j = parent[j];
                cout << "<---" << j;
            } while (j != s);
        }
}


/*
Output of the code:

Enter the number of vertices: 4
Enter the weighted matrix (4x4=16 elements)
0 10 3 20
0 0 0 5
0 2 0 3
0 0 0 0
Enter the sources vertex: 1
The shortest distances from 1 to all other vertices are:
1---->2 is 5 . Path is 2<---3<---1
1---->3 is 3 . Path is 3<---1
1---->4 is 6 . Path is 4<---3<---1
  
  


Enter the number of vertices: 5
Enter the weighted matrix (5x5=25 elements)
0 10 3 0 0
0 0 1 2 0
0 4 0 8 2
0 0 0 0 7
0 0 0 9 0
Enter the sources vertex: 1
The shortest distances from 1 to all other vertices are:
1---->2 is 7 . Path is 2<---3<---1
1---->3 is 3 . Path is 3<---1
1---->4 is 9 . Path is 4<---2<---3<---1
1---->5 is 5 . Path is 5<---3<---1
  
 
*/

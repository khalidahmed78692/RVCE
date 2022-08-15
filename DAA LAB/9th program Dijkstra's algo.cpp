// #include <bits/stdc++.h> // this includes all header files
#include <iostream>
#include <climits>
using namespace std;

void Dijkstras(int cost[10][10], int dist[10], int n, int s)
{
    int i, v, min, count = 1, visited[10];
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;
    while (count <= n)
    {
        min = INT_MAX;
        for (i = 1; i <= n; i++)
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                v = i;
            }
        visited[v] = 1;
        count++;
        for (i = 1; i <= n; i++)
            if (!visited[i] && dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
    }
}

int main()
{
    int i, j, n, s, cost[10][10], dist[10];
    cout << "Enter the number of vertices/nodes: ";
    cin >> n;
    cout << "Enter the weight matrix:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (!cost[i][j])
                cost[i][j] = INT_MAX;
        }
    cout << "Enter the source vertex: ";
    cin >> s;
    Dijkstras(cost, dist, n, s);
    cout << "Shortest distance from " << s << " is\n";
    for (i = 1; i <= n; i++)
        if (s != i)
            cout << s << "-->" << i << " is: " << dist[i] << endl;
}

/*

output of the code:
Enter the number of vertices/nodes: 4
Enter the weight matrix:
0 10 3 20
0 0 0 5
0 2 0 3
0 0 0 0
Enter the source vertex: 1
Shortest distance from 1 is
1-->2 is: 5
1-->3 is: 3
1-->4 is: 6


Enter the number of vertices/nodes: 5
Enter the weight matrix:
0 10 3 0 0
0 0 1 2 0
0 4 0 8 2
0 0 0 0 7
0 0 0 9 0

*/

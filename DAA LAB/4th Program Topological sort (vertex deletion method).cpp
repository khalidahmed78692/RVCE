#include <iostream>
using namespace std;

void verdel(int adjmat[10][10], int indegree[10], int nov, int cur)
{
    indegree[cur] = -1;
    for (int i = 0; i < nov; i++)
        if (adjmat[cur][i])
            indegree[i] -= 1;
}

int main()
{
    int nov, i, j;
    cout << "Enter the number of vertices: ";
    cin >> nov;
    int adjmat[10][10], indegree[10];
    for (i = 0; i < nov; i++)
        indegree[i] = 0;
    cout << "Enter the adjacency matrix\n";
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
        {
            cin >> adjmat[i][j];
            if (adjmat[i][j])
                indegree[j] += 1;
        }
    cout << "Initial indegrees are:";
    for (i = 0; i < nov; i++)
        cout << ' ' << indegree[i];
    cout << "\nTopological sort using vertex deletion method is:";
    for (i = 0; i < nov; i++)
    {
        if (!indegree[i])
        {
            cout << " " << i + 1;
            verdel(adjmat, indegree, nov, i);
            i = -1;
        }
    }
}

/*

Output of the code:

Enter the number of vertices: 4
Enter the adjacency matrix
0 1 0 1
0 0 0 1
0 0 0 0
0 0 1 0
Initial indegrees are: 0 1 1 2
Topological sort using vertex deletion method is: 1 2 4 3


Enter the number of vertices: 7
Enter the adjacency matrix
0 1 1 0 0 0 0
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 1 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 1 1 0
Initial indegrees are: 1 2 2 0 2 3 2
Topological sort using vertex deletion method is: 4 1 2 3 7 5 6

*/

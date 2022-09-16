#include <iostream>
using namespace std;

int main()
{
    int nov;
    cout << "Enter the number of vertices: ";
    cin >> nov;
    int i, j, node, indegree[nov];
    bool adjmat[nov][nov], visitedmat[nov];
    for (i = 0; i < nov; i++)
    {
        indegree[i] = 0;
        visitedmat[i] = false;
    }
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
        {
            cin >> adjmat[i][j];
            if (adjmat[i][j])
                indegree[j]++;
        }
    cout << "Topological sort is:";
    for (i = 0; i < nov; i++)
    {
        for (j = 0; j < nov; j++)
            if (!indegree[j] && !visitedmat[j])
            {
                node = j;
                cout << "\t" << j + 1;
                visitedmat[j] = true;
                break;
            }
        for (j = 0; j < nov; j++)
            if (adjmat[node][j])
                indegree[j]--;
    }
}


/*
Output of the code:

Enter the number of vertices: 7
0 1 1 0 0 0 0
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 1 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 1 1 0
Topological sort is:    4       1       2       3       7       5       6

*/

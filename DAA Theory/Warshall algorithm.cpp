#include <iostream>
using namespace std;

void Warshall_algo(bool R[15][15], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                R[j][k] = R[j][k] || (R[j][i] && R[i][k]);
}

int main()
{
    int n, i, j;
    cout << "Enter the number of vertices: ";
    cin >> n;
    bool R[15][15];
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> R[i][j];
    Warshall_algo(R, n);
    cout << "The transitive closure of the graph is:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << R[i][j] << "\t";
        cout << endl;
    }
}

/*

Output of the code:

Enter the number of vertices: 4
Enter the adjacency matrix:
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
The transitive closure of the graph is:
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1

Enter the number of vertices: 4
Enter the adjacency matrix:
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
The transitive closure of the graph is:
0       0       1       0
1       1       1       1
0       0       0       0
1       1       1       1

*/

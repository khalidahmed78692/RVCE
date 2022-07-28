#include <iostream>
#include <climits>
using namespace std;

void Floyd_Warshall(int D[15][15], int n)
{
    // finding the shortest path
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int i, j, D[15][15];
    cout << "Enter the weighted graph (for infinity enter 99999):\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> D[i][j];
    Floyd_Warshall(D, n);
    // Printing the all shortest path matrix
    cout << "All Shortest path weighted graph in the form of matrix is:";
    for (i = 1; i <= n; i++)
    {
        cout << endl;
        for (j = 1; j <= n; j++)
            if (D[i][j] == 99999)
                cout << "INF\t";
            else
                cout << D[i][j] << "\t";
    }
}

/*

output of the code:

Enter the number of vertices: 4
Enter the weighted graph (for infinity enter 99999):
0 99999 3 99999
2 0 99999 99999
99999 7 0 1
6 99999 99999 0
All Shortest path weighted graph in the form of matrix is:
0       10      3       4
2       0       5       6
7       7       0       1
6       16      9       0


Enter the number of vertices: 4
Enter the weighted graph (for infinity enter 99999):
0 3 99999 5
2 0 99999 4
99999 1 0 99999
99999 99999 2 0
All Shortest path weighted graph in the form of matrix is:
0       3       7       5
2       0       6       4
3       1       0       5
5       3       2       0

*/

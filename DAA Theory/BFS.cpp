#include <iostream>
using namespace std;

int count = 0, nov;

void BFS(bool adj_mat[10][10], int nov, bool ver_mat[], int visited)
{
    ver_mat[visited] = true;
    int queue[nov], front = 0, rear = -1, node;
    queue[++rear] = visited;
    while (front <= rear)
    {
        node = queue[front++];
        for (int i = 0; i < nov; i++)
            if (adj_mat[node][i] && !ver_mat[i])
            {
                ver_mat[i] = true;
                queue[++rear] = i;
                cout << i + 1 << ' ';
            }
    }
}

int main()
{
    cout << "Enter the number of vertices: ";
    cin >> nov;
    bool adj_mat[10][10], ver_mat[nov];
    int i, j;
    cout << "Enter adjacency matrix ( " << nov << " x " << nov << " ): " << endl;
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            cin >> adj_mat[i][j];
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    cout << "BFS order is: ";
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            cout << i + 1 << ' ';
            BFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    if (count == 1)
        cout << endl
             << "Graph is connected";
    else
        cout << endl
             << "Graph is not connected and there are " << count << " pieces of graph";
}

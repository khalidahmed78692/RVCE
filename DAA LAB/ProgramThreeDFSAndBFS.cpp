#include <iostream>
using namespace std;

int count = 0;

void DFS(bool adj_mat[10][10], int nov, bool ver_mat[10], int vtd)
{
    ver_mat[vtd] = true;
    for (int i = 0; i < nov; i++)
        if (adj_mat[vtd][i] && !ver_mat[i])
        {
            cout << i + 1 << " ";
            DFS(adj_mat, nov, ver_mat, i);
        }
}

void BFS(bool adj_mat[10][10], int nov, bool ver_mat[10], int vtd)
{
    int queue[nov], front = 0, rear = -1, node;
    ver_mat[vtd] = true;
    queue[++rear] = vtd;
    while (front <= rear)
    {
        node = queue[front++];
        for (int i = 0; i < nov; i++)
            if (adj_mat[node][i] && !ver_mat[i])
            {
                queue[++rear] = i;
                ver_mat[i] = true;
                cout << i + 1 << ' ';
            }
    }
}

int main()
{
    int nov;
    cout << "Enter the number of vertices: ";
    cin >> nov;
    bool adj_mat[10][10], ver_mat[10];
    int i, j;
    cout << "Enter adjacency matrix ( " << nov << " x " << nov << " elements) :\n";
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            cin >> adj_mat[i][j];
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    cout << "DFS order is: ";
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            cout << i + 1 << ' ';
            DFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    if (count == 1)
        cout << "\nGraph is connected\n";
    else
        cout << "\nGraph is not connected and there are " << count << " components of it\n";
    count = 0;
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    cout << "\nBFS order is: ";
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            cout << i + 1 << " ";
            BFS(adj_mat, nov, ver_mat, i);
            count++;
        }
    if (count == 1)
        cout << "\nGraph is connected";
    else
        cout << "\nGraph is not connected and there are " << count << " components of it";
}

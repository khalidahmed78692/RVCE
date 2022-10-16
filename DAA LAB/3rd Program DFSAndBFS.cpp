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
    cout<<"\n\n|DFS Traversal|\n\n";
    int nov;
    cout << "Enter the number of vertices: ";
    cin >> nov;
    bool adj_mat[10][10], ver_mat[10];
    int i, j;
    cout << "Enter adjacency matrix ( " << nov << " x " << nov << " elements) :\n";
    for (i = 0; i < nov; i++){
        for (j = 0; j < nov; j++)
            cin >> adj_mat[i][j];
        ver_mat[i] = false;
    }
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
        cout << "\nGraph is not connected and it has " << count << " components\n";
    
    
    cout<<"\n\n|BFS Traversal|\n\n";
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



/*

Output of the code:

Enter the number of vertices: 10
Enter adjacency matrix
0 0 1 1 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 1 0 0 0 1 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0 1 0
DFS traversal is: 1 3 6 5 2 4 7 8 9 10



Enter the number of vertices: 7
Enter adjacency matrix
0 1 1 1 1 0 0
1 0 0 1 0 1 0
1 0 0 0 0 0 1
1 1 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0 
0 0 1 0 1 0 0
DFS traversal is: 1 2 4 6 3 7 5

*/

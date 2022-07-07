#include <iostream>
using namespace std;

int count = 0;

void DFS(bool adj_mat[][10], int nov, bool ver_mat[], int visited)
{
    ver_mat[visited] = true; // mark true so that it confirms, that this vertex is visited
    for (int i = 0; i < nov; i++) 
    {
        if (adj_mat[visited][i] && !ver_mat[i]) // check if the vertex from visited is connected to other vertices if so then check if that vertex in not visited
        {
            cout << i + 1 << ' '; // then print that vertex and recursively call the DFS function by passing the appropirate arguments as discussed below.
            DFS(adj_mat, nov, ver_mat, i);
        }
    }
}

int main()
{
    int nov; // nov --> number of vertices
    cout << "Enter the number of vertices: ";
    cin >> nov;
    int i, j;
    bool adj_mat[10][10], ver_mat[nov];
    cout << "Enter the edges connected in graph (adjacency matrix):\n";
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            cin >> adj_mat[i][j];
    /* 1) mark all the vertices of the graph as unvisited
       2) mark false for unvisited */
    for (i = 0; i < nov; i++)
        ver_mat[i] = false;
    // Now perform DFS in alphabetical order, since numbers are used here, so perform DFS in ascending order
    cout << "DFS order is: ";
    for (i = 0; i < nov; i++)
        if (!ver_mat[i])
        {
            cout << i + 1 << ' '; // printing the order of vertices encountered
            DFS(adj_mat, nov, ver_mat, i);
			/* call the function DFS and pass the arugments adjacency matrix, number of vertices, vertices matrix so that visited
            and unvisited can be known, and current vertex number; */
            count++;
            /* This count is to just check whether the graph is connected or not if graph is connected, then DFS function call itself recursively and visit
            all the vertices, and count will be executed next making its value to 1 and further DFS will not be executed because as all the vertices are
            visited before. So count is 1 and below we check if count is one, then we say that graph is connected else graph is not connected and also how many times
            count gets executed reveals that in given graph so is the number of components. */
        }
    if (count == 1)
        cout << "\nGraph is connected";
    else
        cout << "\nGraph is not connected and there are " << count << " components in given graph";
}

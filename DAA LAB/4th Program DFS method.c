/* 
output of the code
Enter the number of vertices: 7
Enter the adjacency matrix (7 x 7):
0 1 1 0 0 0 0
0 0 0 0 1 0 1
0 0 0 0 0 1 0
1 1 1 0 0 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 1 1 0
Popping order is: 5 6 7 2 3 1 4 
Topological ordering / sort is: 4 1 3 2 7 6 5 
Graph is not connected and there are 2 components of it
*/

#include <iostream>
using namespace std;

int count = 0, pop_array[10], ptr = -1;
// pop_array[] --> to store the popping order of the DFS method
// ptr --> pointer to the array to store at specified location 
// count --> to check whether the graph is connected or not 
void dfs(bool adj[10][10], int nov, bool ver_mat[10], int vstd)
// dfs function to recursive call the adjacent nodes

{
    ver_mat[vstd] = true;// ver_mat[] --> is a vertex matrix, which sets true when current vertex is visited
    for (int i = 0; i < nov; i++) // from current vertex, check which all vertex is connected by edges to other vertex
        if (adj[vstd][i] && !ver_mat[i]) // also check if that vertex is visited or not, if visited then don't go to that vertex once again, else go recursively
            dfs(adj, nov, ver_mat, i);
    cout << vstd + 1 << ' '; // once we reach the dead end, print that vertex, then reason +1 is start printing from 1 rather than 0, and place that vertex to the popped array
    pop_array[++ptr] = vstd;
}

void DFS(bool adj[10][10], int nov)
{
    bool ver_mat[10]; // create vertex matrix of given size
    int i;
    for (i = 0; i < nov; i++) // and initialize it to false, which means it is not visited
        ver_mat[i] = false;

    cout << "Popping order is: ";
    for (i = 0; i < nov; i++) // this is just DFS traversal, when in dfs function dead end is reached, then print the dead end in dfs function
        if (!ver_mat[i])
        {
            dfs(adj, nov, ver_mat, i);
            count++;
        }
}

int main()
{
    int nov, i, j;
    bool adj[10][10]; // create 2-D adjacency matrix
    cout << "Enter the number of vertices: ";
    cin >> nov;
    cout << "Enter the adjacency matrix ( " << nov << " x " << nov << " elements):\n";
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            cin >> adj[i][j];

    DFS(adj, nov);

    // reversing the popping order
    // int swap;
    // for (i = 0; i <= ptr / 2; i++)
    // {
    //     swap = pop_array[i];
    //     pop_array[i] = pop_array[ptr - i];
    //     pop_array[ptr - i] = swap;
    // }

    cout << "\nTopological order is: ";

    // When above revere is done, then use this for loop and comment below one else you can use as usual
    // for (i = 0; i <= ptr; i++)
    //     printf("%d ", pop_array[i] + 1);

    for (i = ptr; i >= 0; i--)
        cout << pop_array[i] + 1 << " ";
    cout << endl;
    if (count == 1)
        cout << "Graph is connected";
    else
        cout << "Graph is not connected and there are " << count << " components of it";
}

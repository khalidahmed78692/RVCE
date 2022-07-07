#include <stdio.h>

int count = 0,nov; // nov --> number of vertices

void DFS(int adj_mat[nov][nov], int nov, int ver[nov], int vis)
{
    ver[vis] = 1; // mark the vertex as visited by assigning 1 value, so that it will not be considered in further search
    for (int i = 0; i < nov; i++)
    {
        if (adj_mat[vis][i] == 1 && ver[i] == 0) /* check if the vertex from current vertex is connected to other vertices if so then check if that vertex
													in not visited */
        {
            printf("%d ", i+1); // then print that vertex
            DFS(adj_mat, nov, ver, i); //  and recursively call the DFS function by passing the appropirate arguments as discussed below
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &nov);
    int i, j, adj_mat[nov][nov];
    int ver[nov];
    printf("Enter the number of edges in the adjacency matrix:\n");
    for (i = 0; i < nov; i++)
        for (j = 0; j < nov; j++)
            scanf("%d", &adj_mat[i][j]);
    /* 1) mark all the vertices of the graph as unvisited
       2) mark 0 for unvisited */
    for (i = 0; i < nov; i++)
        ver[i] = 0;
    printf("DFS order is: ");
	// Now perform DFS in alphabetical order, since numbers are used here, so perform DFS in ascending order
    for (i = 0; i < nov; i++)
        if (!ver[i])
        {
            printf("%d ", i+1); // printing the order of vertices encountered
            DFS(adj_mat, nov, ver, i);
			/* call the function DFS and pass the arugments adjacency matrix, number of vertices, vertices matrix so that visited
               and unvisited can be known, and current vertex number; */
            count++;
			/* This count is to just check whether the graph is connected or not if graph is connected, then DFS function call itself recursively and visit
            all the vertices, and count will be executed next making its value to 1 and further DFS will not be executed because as all the vertices are
            visited before. So count is 1 and below we check if count is one, then we say that graph is connected else graph is not connected and also how many times
            count gets executed reveals that in given graph so is the number of components. */
        }
    if (count == 1)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected and there are %d graph components.", count);
    return 0;
}

/*
Enter the number of vertices: 7
Enter the adjacency matrix (7 x 7 elements):
false true true false false false false
false false false false true false true
false false false false false true false
true true true false false true true
false false false false false false false
false false false false false false false
false false false false true true false
Popping order is: 5 6 7 2 3 1 4 
Topological sort "or" ordering is: 4 1 3 2 7 6 5 
Graph is not connected and there are 2 components of it
*/

import java.util.Scanner;

public class FourthProgramTopologicalSortUsingDFS {
    static byte nov,count=0,ptr=-1;
    // ptr --> pointer to the array to store at specified location
    // count --> to check whether the graph is connected or not

    static byte[] pop_array=new byte[10];
    // pop_array[] --> to store the popping order of the DFS method

    static void dfs(boolean[][] adj,byte nov, boolean[] ver_mat, byte vstd){ // dfs function to recursive call the adjacent nodes
        ver_mat[vstd]=true; // ver_mat[] --> is a vertex matrix, which sets true when current vertex is visited
        for(byte i=0;i<nov;i++) // from current vertex, check which all vertex is connected by edges to other vertex
            if(adj[vstd][i]&&!ver_mat[i]) // also check if that vertex is visited or not, if visited then don't go to that vertex once again, else go recursively
                dfs(adj,nov,ver_mat,i);
        System.out.print((vstd+1)+" "); // once we reach the dead end, print that vertex, then reason +1 is start printing from 1 rather than 0, and place that vertex to the popped array
        pop_array[++ptr]=vstd;
    }

    static void DFS(boolean[][] adj,byte nov){
        boolean[] ver_mat= new boolean[nov]; // create vertex matrix of given size

        // if you don't initialize the ver_mat[] to false, it is ok because in java by default it will be initialize to false
        System.out.print("Popping order is: ");
        for(byte i=0;i<nov;i++) // this is just DFS traversal, when in dfs function dead end is reached, then print the dead end in dfs function
            if(!ver_mat[i]){
                dfs(adj,nov,ver_mat,i);
                count++;
            }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        byte nov=sc.nextByte();
        byte i,j;
        boolean[][] adj=new boolean[nov][nov]; // create 2-D adjacency matrix
        System.out.printf("Enter the adjacency matrix (%d x %d elements):\n",nov,nov);
        for(i=0;i<nov;i++)
            for(j=0;j<nov;j++)
                adj[i][j]=sc.nextBoolean();

        DFS(adj,nov);

        // reversing the popping array
//        byte swap;
//        for(i=0;i<=ptr/2;i++){
//            swap=pop_array[i];
//            pop_array[i]=pop_array[ptr-i];
//            pop_array[ptr-i]=swap;
//        }

        System.out.print("\nTopological sort \"or\" ordering is: ");
        // When above revere is done, then use this for loop and comment below one else you can use as usual
        // for(i=0;i<=ptr;i++)
        // System.out.print((pop_array[i]+1)+" ");

        for(i=ptr;i>=0;i--)
            System.out.print((pop_array[i]+1)+" ");

        if(count==1)
            System.out.println("\nGraph is connected");
        else
            System.out.println("\nGraph is not connected and there are "+count+" components of it");
    }
}

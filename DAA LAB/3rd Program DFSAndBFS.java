
import java.util.Scanner;

public class DFSAndBFS {
    static int count=0;

    static void DFS(boolean[][] adj_mat, byte nov, boolean[] ver_mat, byte vtd){
        ver_mat[vtd]=true;
        for(byte i=0;i<nov;i++)
        {
            if(adj_mat[vtd][i]&&!ver_mat[i]){
                System.out.print((i+1)+" ");
                DFS(adj_mat,nov,ver_mat,i);
            }
        }
    }

    static void BFS(boolean[][] adj_mat, byte nov, boolean[] ver_mat, byte vtd)
    {
        byte[] queue=new byte[nov];
        byte front=0,rear=-1,node;
        ver_mat[vtd]=true;
        queue[++rear]=vtd;
        while(front<=rear)
        {
            node = queue[front++];
            for(byte i=0;i<nov;i++)
                if(adj_mat[node][i]&&!ver_mat[i]){
                    System.out.print((i+1)+" ");
                    ver_mat[i]=true;
                    queue[++rear]=i;
                }
        }

    }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        byte nov=in.nextByte();
        boolean[][] adj_mat=new boolean[nov][nov];
        boolean[] ver_mat=new boolean[nov];
        byte i,j;
        System.out.println("Enter adjacency matrix ( "+nov+" x "+nov+" elements):");
        for(i=0;i<nov;i++)
            for(j=0;j<nov;j++)
                adj_mat[i][j]=in.nextBoolean();
        for(i=0;i<nov;i++)
            ver_mat[i]=false;
        System.out.print("DFS order is: ");
        for(i=0;i<nov;i++)
            if(!ver_mat[i])
            {
                System.out.print((i+1)+" ");
                DFS(adj_mat,nov,ver_mat,i);
                count++;
            }
        if(count==1)
            System.out.println("\nGraph is connected");
        else
            System.out.println("\nGraph is not connected and there are "+count+" components of it");
        count=0;
        for(i=0;i<nov;i++)
            ver_mat[i]=false;
        System.out.print("\nBFS order is: ");
        for(i=0;i<nov;i++)
            if(!ver_mat[i])
            {
                System.out.print((i+1)+" ");
                BFS(adj_mat,nov,ver_mat,i);
                count++;
            }
        if(count==1)
            System.out.println("\nGraph is connected");
        else
            System.out.println("\nGraph is not connected and there are "+count+" components of it");

    }
}

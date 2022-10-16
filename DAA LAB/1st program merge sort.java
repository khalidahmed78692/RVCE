import java.util.Scanner;
import java.util.Random;

public class MergeSort {

    static int count=0;

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n=sc.nextInt();
        int[] a=new int[n];
        System.out.print("Enter "+n+" elements: ");
        int i,j;
        for(i=0;i<n;i++)
            a[i]=sc.nextInt();
        mergeSort(a,0,n-1);
        System.out.print("Merge sorted array is:");
        for(int var:a)
            System.out.print(" "+var);
        System.out.println("\nNumber of times basic operation executed is: "+count);
        int c1,c2;
        System.out.println("Time complexity table is");
        System.out.println("n\ta\tr\td");
        for(i=1;i<=4096;i*=2){
            int[] asc=new int[i];
            int[] rand=new int[i];
            int[] des=new int[i];
            Random random=new Random(i);
            for(j=0;j<i;j++)
            {
                asc[j]=j+1;
                rand[j]=random.nextInt();
                des[j]=i-j;
            }
            count=0;
            mergeSort(asc,0,i-1);
            c1=count;
            count=0;
            mergeSort(rand,0,i-1);
            c2=count;
            count=0;
            mergeSort(des,0,i-1);
            System.out.println(i+"\t"+c1+"\t"+c2+"\t"+count);
        }
    }

    public static void mergeSort(int[] a,int l,int r)
    {
        if(l<r){
            count++;
            int m=l+(r-l)/2;
            mergeSort(a,l,m);
            mergeSort(a,m+1,r);
            conquer(a,l,m,r);
        }
    }

    static void conquer(int[] a,int l,int m,int r)
    {
        int i=l,j=m+1,k=l;
        int[] b=new int[r+1];
        while(i<=m&&j<=r)
        {
            count++;
            if(a[i]<a[j])
                b[k++]=a[i++];
            else
                b[k++]=a[j++];
        }
        while(i<=m)
            b[k++]=a[i++];
        while(j<=r)
            b[k++]=a[j++];
        for(i=l;i<=r;i++)
            a[i]=b[i];
    }
}


/*

Output of the code:

Enter the number of elements: 4
Enter 4 elements: 4 1 3 2
Merge sorted array is: 1 2 3 4
Number of times basic operation executed is: 8
Time complexity table is
n	a	r	d
1	0	0	0
2	2	2	2
4	7	8	7
8	19	22	19
16	47	61	47
32	111	160	111
64	255	370	255
128	575	872	575
256	1279	1982	1279
512	2815	4475	2815
1024	6143	9974	6143
2048	13311	22003	13311
4096	28671	48073	28671



Enter the number of elements: 10
Enter 10 elements: 1 54 51 651 165 61 74 9846 1 49
Merge sorted array is: 1 1 49 51 54 61 74 165 651 9846
Number of times basic operation executed is: 31
Time complexity table is
n	a	r	d
1	0	0	0
2	2	2	2
4	7	8	7
8	19	22	19
16	47	61	47
32	111	160	111
64	255	370	255
128	575	872	575
256	1279	1982	1279
512	2815	4475	2815
1024	6143	9974	6143
2048	13311	22003	13311
4096	28671	48073	28671

*/

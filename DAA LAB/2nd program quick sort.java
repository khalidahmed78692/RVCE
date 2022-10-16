import java.util.Random;
import java.util.Scanner;

public class QuickSort {

    static int count=0;

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n=sc.nextInt();
        int[] a=new int[n];
        System.out.print("Enter "+n+" elements: ");
        int i;
        for(i=0;i<n;i++)
            a[i]=sc.nextInt();
        quickSort(a,0,n-1);
        System.out.print("Quick sorted array is:");
        for(int var:a)
            System.out.print(" "+var);
        System.out.println("\nNumber of times basic operation executed is: "+count);
        int c1,c2,j;
        System.out.println("Time complexity table is");
        System.out.println("n\ta\tr\td");
        for(i=1;i<=4096;i*=2)
        {
            int[] asc=new int[i];
            int[] ran=new int[i];
            int[] des=new int[i];
            Random random=new Random(i);
            for(j=0;j<i;j++)
            {
                asc[j]=j+1;
                ran[j]=random.nextInt();
                des[j]=i-j;
            }
            count=0;
            quickSort(asc,0,i-1);
            c1=count;
            count=0;
            quickSort(ran,0,i-1);
            c2=count;
            count=0;
            quickSort(des,0,i-1);
            System.out.println(i+"\t"+c1+"\t"+c2+"\t"+count);
        }
    }

    static void quickSort(int[] a,int l,int r)
    {
        count++;
        if(l<r)
        {
            int s=partition(a,l,r);
            quickSort(a,l,s-1);
            quickSort(a,s+1,r);
        }
    }

    static int partition(int[] a,int l,int r)
    {
        int pivot=a[l],i=l+1,j=r;
        while(true)
        {
            count++;
            while(i<=r&&pivot>=a[i]) {
                i++;
            }
            while(pivot<a[j]) {
                j--;
            }
            if(i<j)
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            else{
                int temp=a[l];
                a[l]=a[j];
                a[j]=temp;
                return j;
            }
        }
    }
}

/*

Output of the code:

Enter the number of elements: 7
Enter 7 elements:  165 51 1 1 1 31 61 
Quick sorted array is: 1 1 1 31 51 61 165
Number of times basic operation executed is: 17
Time complexity table is
n	a	r	d
1	1	1	1
2	4	4	4
4	10	8	10
8	22	15	22
16	46	37	46
32	94	85	94
64	190	188	190
128	382	379	382
256	766	858	766
512	1534	1793	1534
1024	3070	3843	3070
2048	6142	8087	6142
4096	12286	17305	12286


Enter the number of elements: 3
Enter 3 elements: 1 4856 165 
Quick sorted array is: 1 165 4856
Number of times basic operation executed is: 7
Time complexity table is
n	a	r	d
1	1	1	1
2	4	4	4
4	10	8	10
8	22	15	22
16	46	37	46
32	94	85	94
64	190	188	190
128	382	379	382
256	766	858	766
512	1534	1793	1534
1024	3070	3843	3070
2048	6142	8087	6142
4096	12286	17305	12286


*/

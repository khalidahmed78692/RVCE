
import java.util.Scanner;

public class ArrayUniquenessUsingPreSort {

    static void mergesort_con(int a[], byte left, byte mid, byte right)
    {
        byte i=left, j=(byte)(mid+1), k=left;
        int[] b=new int[(byte)(right+1)];
        while(i<=mid&&j<=right)
            if(a[i]<a[j])
                b[k++]=a[i++];
            else
                b[k++]=a[j++];
        while(i<=mid)
            b[k++]=a[i++];
        while(j<=right)
            b[k++]=a[j++];
        for(i=left;i<=right;i++)
            a[i]=b[i];
    }

    static void mergesort_div(int a[], byte left, byte right)
    {
        if(left<right)
        {
            byte mid=(byte)(left+(right-left)/2);
            mergesort_div(a,left,mid);
            mergesort_div(a,(byte)(mid+1),right);
            mergesort_con(a,left,mid,right);
        }
    }

    static boolean uniqueness(int a[],byte n)
    {
        for(byte i=0;i<n-1;i++)
            if(a[i]==a[i+1])
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        byte n=sc.nextByte(),i;
        int[] a= new int[n];
        System.out.print("Enter "+n+" elements: ");
        for(i=0;i<n;i++)
            a[i]=sc.nextInt();
        // Sorting
        mergesort_div(a,(byte)0,(byte)(n-1));
        System.out.print("Merge sorted array is:");
        for(int ele:a)
            System.out.print(" "+ele);
        // Uniqueness
        System.out.println("\nArray uniqueness is: "+uniqueness(a,n));
    }
}
/*
output of the code


Enter the size of the array: 10
Enter 10 elements:  195 1 5646 1984 619874 51984 1 4981 6456 156   
Merge sorted array is: 1 1 156 195 1984 4981 5646 6456 51984 619874
Array uniqueness is: False


Enter the size of the array: 16
Enter 16 elements:  746 517 1 598 1978 84 61 18 4187 5798 461 87 9813 498 12  13
Merge sorted array is: 1 12 13 18 61 84 87 461 498 517 598 746 1978 4187 5798 9813
Array uniqueness is: true

*/

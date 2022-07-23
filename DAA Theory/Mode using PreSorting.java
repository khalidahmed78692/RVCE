import java.util.Scanner;

public class ModeUsingPreSorting {
    static void mergesort_con(int a[], byte left, byte mid, byte right)
    {
        byte i=left,j= (byte) (mid+1),k=left;
        int[] b = new int[right+1];
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
    static void mergesort_div(int a[],byte left, byte right)
    {
        if(left<right)
        {
            byte mid= (byte) (left+(right-left)/2);
            mergesort_div(a,left, mid);
            mergesort_div(a, (byte) (mid+1),right);
            mergesort_con(a,left,mid,right);
        }
    }

    static int mode(int a[],int n)
    {
        byte i,runLen,modFreq=0;
        int runVal,modVal=0;
        for(i=0;i<n;i++)
        {
            runLen=1;
            runVal=a[i];
            while(i+runLen<n&&a[i+runLen]==runVal)
                runLen+=1;
            if(runLen>modFreq)
            {
                modFreq=runLen;
                modVal=runVal;
            }
            i+=runLen;
        }
        if(modVal==0)
            return -1;
        else
            return modVal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the list: ");
        byte i, n=sc.nextByte();
        int[] a= new int[n];
        System.out.print("Enter "+n+" elements: ");
        for(i=0;i<n;i++)
            a[i]=sc.nextInt();
        mergesort_div(a, (byte) 0,(byte)(n-1));
        System.out.print("Merge sorted list is:");
        for(int ele:a)
            System.out.print(" "+ele);
        System.out.println("\nMode of the given list is: "+mode(a,n));
    }
}
/* output of the code
Enter the size of the list: 15
Enter 15 elements: -1  98 11 66 46 5 11 11 11 -89 0 0 11 45 11
Merge sorted list is: -89 -1 0 0 5 11 11 11 11 11 11 45 46 66 98
Mode of the given list is: 11
*/

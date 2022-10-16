#include <stdio.h>
#include <stdlib.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int a[], int n, int i)
{
    int left = 2 * i, right = left + 1, highest = i;
    if (left <= n)
    {
        count++;
        if (a[left] > a[i])
            highest = left;
    }
    if (right <= n)
    {
        count++;
        if (a[highest] < a[right])
            highest = right;
    }
    if (highest != i)
    {
        swap(&a[i], &a[highest]);
        Heapify(a, n, highest);
    }
}

void heapify(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        Heapify(a, n, i);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int m = n, a[n], i;
    printf("Enter %d elements: ", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    heapify(a, n);
    while (1)
    {
        if (n == 1)
            break;
        swap(&a[1], &a[n]);
        n--;
        Heapify(a, n, 1);
    }
    printf("Heap sorted array is:");
    for (i = 1; i <= m; i++)
        printf("\t%d", a[i]);
    printf("\nThe number of times basic operation executed is: %d\n", count);
    int c1, c2, j;
    printf("Time complexity table\n");
    printf("size\tasc\tdes\trand\n");
    for (i = 1; i <= 4096; i *= 2)
    {
        int a[i], d[i], r[i];
        for (j = 1; j <= i; j++)
        {
            a[j] = j;
            d[j] = i - j;
            r[j] = rand() % i;
        }
        count = 0;
        heapify(a, i);
        m = i;
        while (1)
        {
            if (m == 1)
                break;
            swap(&a[1], &a[m]);
            m--;
            Heapify(a, m, 1);
        }
        c1 = count;
        m = i;
        count = 0;
        while (1)
        {
            if (m == 1)
                break;
            swap(&d[1], &d[m]);
            m--;
            Heapify(d, m, 1);
        }
        c2 = count;
        count = 0;
        heapify(r, i);
        m = i;
        while (1)
        {
            if (m == 1)
                break;
            swap(&r[1], &r[m]);
            m--;
            Heapify(r, m, 1);
        }
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, count);
    }
}

/*

Output of the code:

Enter the number of elements: 5
Enter 5 elements:  165  132 1 156 165
Heap sorted array is:   1       132     156     165     165
The number of times basic operation executed is: 10        
Time complexity table
size    asc     des     rand
1       0       0       0
2       1       0       1
4       7       3       7
8       27      17      22
16      85      57      82
32      231     171     222
64      593     462     573
128     1459    1167    1396
256     3452    2851    3317
512     7958    6692    7621
1024    18060   15384   17254
2048    40204   34926   38749
4096    88835   78209   85614



Enter the number of elements: 9
Enter 9 elements:  156 161 561 61 516 1 16 4 16  
Heap sorted array is:   1       4       16      16      61      156     161     516     561
The number of times basic operation executed is: 31
Time complexity table
size    asc     des     rand
1       0       0       0
2       1       0       1
4       7       3       7
8       27      17      22
16      85      57      82
32      231     171     222
64      593     462     573
128     1459    1167    1396
256     3452    2851    3317
512     7958    6692    7621
1024    18060   15384   17254
2048    40204   34926   38749
4096    88835   78209   85614

*/

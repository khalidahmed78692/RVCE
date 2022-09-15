#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l, b[r + 1];
    while (i <= m && j <= r)
    {
        count++;
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = b[i];
}

void merge_sort(int a[], int l, int r)
{

    if (l < r)
    {
        count++;
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n], i;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    printf("The Merge sorted array is:");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    printf("\nBasic operation executed is: %d times\n", count);
    printf("Table of number of times basic operation gets executed:\n");
    printf("n\tasc\tdes\trand\n");
    int c1, c2;
    for (i = 2; i <= 1024; i *= 2)
    {
        int a[i], b[i], c[i], j;
        for (j = 0; j < i; j++)
        {
            a[j] = j;
            b[j] = i - j;
            c[j] = rand();
        }
        count = 0;
        merge_sort(a, 0, i - 1);
        c1 = count;
        count = 0;
        merge_sort(b, 0, i - 1);
        c2 = count;
        count = 0;
        merge_sort(c, 0, i - 1);
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, count);
    }
    return 0;
}


/*

output of the program:

Enter the size of the array: 10
Enter 10 elements: 1 4 51 65498 1 5187  54 616 465 156 
The Merge sorted array is:      1       1       4       51      54      156     465     616     5187    65498
Basic operation executed is: 33 times
Table of number of times basic operation gets executed:
n       asc     des     rand
2       2       2       2
4       7       7       8
8       19      19      24
16      47      47      58
32      111     111     146
64      255     255     369
128     575     575     863
256     1279    1279    1976
512     2815    2815    4495
1024    6143    6143    9973


Enter the size of the array: 5
Enter 5 elements: 5 4 3 2 1
The Merge sorted array is:      1       2       3       4       5
Basic operation executed is: 9 times
Table of number of times basic operation gets executed:
n       asc     des     rand
2       2       2       2
4       7       7       8
8       19      19      24
16      47      47      58
32      111     111     146
64      255     255     369
128     575     575     863
256     1279    1279    1976
512     2815    2815    4495
1024    6143    6143    9973


*/

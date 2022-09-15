#include <stdio.h>
#include <stdlib.h>

int count = 0;

int partition(int array[], int left, int right)
{
    int i = left + 1, j = right, pivot = array[left];
    while (1)
    {
        while (pivot >= array[i] && i <= right)
        {
            count++;
            i++;
        }
        while (pivot < array[j])
        {
            count++;
            j--;
        }
        if (i < j)
        {
            int swap = array[i];
            array[i] = array[j];
            array[j] = swap;
        }
        else
        {
            int swap = array[left];
            array[left] = array[j];
            array[j] = swap;
            return j;
        }
    }
}

void quick_sort(int array[], int left, int right)
{
    int s;
    if (left < right)
    {
        s = partition(array, left, right);
        quick_sort(array, left, s - 1);
        quick_sort(array, s + 1, right);
    }
}

int main()
{

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n], i;
    printf("Enter the elements (%d): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    quick_sort(array, 0, n - 1);
    printf("The sorted array is:");
    for (i = 0; i < n; i++)
        printf("\t%d", array[i]);
    printf("\nNumber of times basic operation executed is: %d", count);
    printf("\n\nTime complexity table\n");
    printf("size\tasc\trand\tdes\n");
    int j, c1, c2;
    for (i = 2; i <= 4096; i *= 2)
    {
        int a[i], d[i], r[i];
        for (j = 0; j < i; j++)
        {
            a[j] = j + 1;
            d[j] = i - j;
            r[j] = rand() % i;
        }
        count = 0;
        quick_sort(a, 0, i - 1);
        c1 = count;
        count = 0;
        quick_sort(r, 0, i - 1);
        c2 = count;
        count = 0;
        quick_sort(d, 0, i - 1);
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, count);
    }
    return 0;
}



/*

Output of the code:

nter the size of the array: 4
Enter the elements (4): 1 2 3 4
The sorted array is:    1       2       3       4
Number of times basic operation executed is: 6

Time complexity table
size    asc     rand    des
2       1       1       1
4       6       5       6
8       28      20      28
16      120     52      120
32      496     158     496
64      2016    316     2016
128     8128    869     8128
256     32640   2088    32640
512     130816  4735    130816
1024    523776  11167   523776
2048    2096128 25949   2096128
4096    8386560 57740   8386560



Enter the size of the array: 8
Enter the elements (8): 8 4 2 1 5 7 3 6
The sorted array is:    1       2       3       4       5       6       7       8
Number of times basic operation executed is: 19

Time complexity table
size    asc     rand    des
2       1       1       1
4       6       5       6
8       28      20      28
16      120     52      120
32      496     158     496
64      2016    316     2016
128     8128    869     8128
256     32640   2088    32640
512     130816  4735    130816
1024    523776  11167   523776
2048    2096128 25949   2096128
4096    8386560 57740   8386560


*/

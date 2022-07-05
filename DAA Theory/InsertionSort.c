#include <stdio.h>
#include <stdlib.h>

int count = 0;

void InsertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        count++;
        for (j = i - 1; (a[j] > temp) && (j >= 0); j--, count++)
        {
            a[j + 1] = a[j];
            if (j == 0)
                break;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int i, a[n];
    printf("Enter %d elments: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    InsertionSort(a, n);
    printf("Sorted array is:");
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
    printf("\nNumber of comparisons made are: %d\n", count);
    printf("||Time complexity table||\n");
    printf("size\tasc\tdes\trandom\n");
    int c1, c2;
    for (i = 1; i <= 15; i++)
    {
        int a[i], b[i], c[i];
        for (int j = 0; j < i; j++)
        {
            a[j] = j;
            b[j] = i - 1 - j;
            c[j] = rand() % i;
        }
        count = 0;
        InsertionSort(a, i);
        c1 = count;
        count = 0;
        InsertionSort(b, i);
        c2 = count;
        count = 0;
        InsertionSort(c, i);
        printf("%d\t%d\t%d\t%d\n", i, c1, c2, count);
    }
    return 0;
}

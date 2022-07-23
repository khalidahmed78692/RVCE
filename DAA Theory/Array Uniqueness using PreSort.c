#include <stdio.h>
#include <stdbool.h>

void mergesort_con(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left, b[right + 1];
    while (i <= mid && j <= right)
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= right)
        b[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = b[i];
}

void mergesort_div(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort_div(a, left, mid);
        mergesort_div(a, mid + 1, right);
        mergesort_con(a, left, mid, right);
    }
}

bool uniqueness(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
            return false;
    return true;
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
    // Sorting
    mergesort_div(a, 0, n - 1);
    printf("Merge sorted array is:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");
    // Array Uniqueness
    bool check = uniqueness(a, n);
    if (check)
        printf("Array uniqueness is: True");
    else
        printf("Array uniqueness is: False");
}

/*
output of the code


Enter the size of the array: 15
Enter 15 elements: 1 4 561 66 198465 15456 154561 5451 6145 165465 1451 54 6516 1 1
Merge sorted array is: 1 1 1 4 54 66 561 1451 5451 6145 6516 15456 154561 165465 198465
Array uniqueness is: False


Enter the size of the array: 13
Enter 13 elements:  498 49844 98791 321 32197561 4 9 32156 7 1 2641 3216 13 
Merge sorted array is: 1 4 7 9 13 321 498 2641 3216 32156 49844 98791 32197561
Array uniqueness is: True

*/

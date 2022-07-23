#include <stdio.h>

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

int mode(int a[], int n)
{
    int i, modfreq = 0, runlen, runval, modval;
    for (i = 0; i < n; i++)
    {
        runlen = 1;
        runval = a[i];
        while (i + runlen < n && a[i + runlen] == runval)
            runlen += 1;
        if (runlen > modfreq)
        {
            modfreq = runlen;
            modval = runval;
        }
        i += runlen;
    }
    return modval;
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
    mergesort_div(a, 0, n - 1);
    printf("Merge sorted array is:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\nThe mode of the given list of numbers is: %d", mode(a, n));
    return 0;
}

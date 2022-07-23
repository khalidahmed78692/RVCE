/* This program is to find the mode of the given list of numbers, where
   we gonna first sort the array using efficient sorting algorithm, which at present
   we know is merge sort but later you'll come to know that heap sort is even better than merge sort
   because heap sort is in-place algo. So for this program we gonna use is merge sort, whose efficiency is (n*log(n))
*/

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
    int modfreq = 0, i, runlen, runval, modval;
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
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n], i;
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    // first let's sort the array
    mergesort_div(a, 0, n - 1);
    cout << "Merge sorted array is:";
    for (i = 0; i < n; i++)
        cout << " " << a[i];
    cout << "\nThe mode of the given list of numbers is: " << mode(a, n);
}

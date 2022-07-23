//#include <bits/stdc++.h>
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
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n], i;
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    // sorting
    mergesort_div(a, 0, n - 1);
    cout << "Merge sorted array is:";
    for (i = 0; i < n; i++)
        cout << ' ' << a[i];
    cout << endl;
    // Uniqueness check
    bool check = uniqueness(a, n);
    if (check)
        cout << "Array uniqueness is: True";
    else
        cout << "Array uniqueness is: False";
}

/*

output of the code


Enter the size of the array: 14 
Enter 14 elements:  984 16 1984 981 654 1324 983 165 19684 321561 67 51685 1968 4314       
Merge sorted array is: 16 67 165 654 981 983 984 1324 1968 1984 4314 19684 51685 321561
Array uniqueness is: True


Enter the size of the array: 10
Enter 10 elements:  195 1 5646 1984 619874 51984 1 4981 6456 156   
Merge sorted array is: 1 1 156 195 1984 4981 5646 6456 51984 619874
Array uniqueness is: False

*/

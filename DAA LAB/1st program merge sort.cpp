#include <iostream>
using namespace std;

int count = 0;

void conquer(int a[], int l, int m, int r)
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

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        count++;
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        conquer(a, l, m, r);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n], i;
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    cout << "Merge sorted array is:";
    for (i = 0; i < n; i++)
        cout << "\t" << a[i];
    cout << "\nNo of times basic operation executed is: " << count;
    int c1, c2, j;
    cout << "\n\nTime complexity table:\n";
    cout << "size\tasc\trand\tdes\n";
    for (i = 1; i <= 4096; i *= 2)
    {
        int asc[i], d[i], r[i];
        for (j = 0; j < i; j++)
        {
            asc[j] = j + 1;
            d[j] = i - j;
            r[j] = rand()%i;
        }
        count = 0;
        mergesort(asc, 0, i - 1);
        c1 = count;
        count = 0;
        mergesort(r, 0, i - 1);
        c2 = count;
        count = 0;
        mergesort(d, 0, i - 1);
        cout << i << "\t" << c1 << "\t" << c2 << "\t" << count << endl;
    }
}


/*

output of the code:

Enter the number of elements: 2
Enter 2 elements: 1 2
Merge sorted array is:  1       2
No of times basic operation executed is: 2

Time complexity table:
size    asc     rand    des
1       0       0       0
2       2       2       2
4       7       8       7
8       19      23      19
16      47      60      47
32      111     152     111
64      255     366     255
128     575     862     575
256     1279    1968    1279
512     2815    4462    2815
1024    6143    9973    6143
2048    13311   21992   13311
4096    28671   48053   28671
	
	
Enter the number of elements: 8
Enter 8 elements: 4 8 2 6 1 5 7 3
Merge sorted array is:  1       2       3       4       5       6       7       8
No of times basic operation executed is: 24

Time complexity table:
size    asc     rand    des
1       0       0       0
2       2       2       2
4       7       8       7
8       19      23      19
16      47      60      47
32      111     152     111
64      255     366     255
128     575     862     575
256     1279    1968    1279
512     2815    4462    2815
1024    6143    9973    6143
2048    13311   21992   13311
4096    28671   48053   28671	
	
*/

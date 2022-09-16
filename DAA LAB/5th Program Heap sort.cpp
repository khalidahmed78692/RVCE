#include <iostream>
using namespace std;

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int left = 2 * i, right = left + 1, highest = i;
    if (left <= n)
    {
        count++;
        if (a[left] > a[i])
            highest = left;
        else
            highest = i;
    }
    if (right <= n)
    {
        count++;
        if (a[right] > a[highest])
            highest = right;
    }
    if (highest != i)
    {
        swap(&a[highest], &a[i]);
        heapify(a, n, highest);
    }
}

void Heapify(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(a, n, i);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n], i, m;
    cout << "Enter " << n << " elements: ";
    for (i = 1; i <= n; i++)
        cin >> a[i];
    Heapify(a, n);
    m = n;
    while (m > 1)
    {
        swap(&a[1], &a[m]);
        heapify(a, --m, 1);
    }
    cout << "Heap sorted array is:";
    for (i = 1; i <= n; i++)
        cout << "\t" << a[i];
    cout << "\nNumber of times basic operation executed is: " << count << endl;

    cout << "Time complexity table is:\n";
    cout << "size\tasc\trand\tdes\n";
    int c1, c2, j;
    for (i = 1; i <= 4096; i *= 2)
    {
        int a[i], r[i], d[i];
        for (j = 1; j <= i; j++)
        {
            a[j] = j;
            r[j] = rand() % i;
            d[j] = i - j + 1;
        }
        count = 0;
        Heapify(a, i);
        m = i;
        while (m > 1)
        {
            swap(&a[1], &a[m]);
            heapify(a, --m, 1);
        }
        c1 = count;
        count = 0;
        Heapify(r, i);
        m = i;
        while (m > 1)
        {
            swap(&r[1], &r[m]);
            heapify(r, --m, 1);
        }
        c2 = count;
        count = 0;
        m = i;
        while (m > 1)
        {
            swap(&d[1], &d[m]);
            heapify(d, --m, 1);
        }
        cout << i << "\t" << c1 << "\t" << c2 << "\t" << count << endl;
    }
}



/*
Output of the code:

Enter the number of elements: 5
Enter 5 elements: 21461 56 1 16 
516
Heap sorted array is:   1       16      56      516     21461
Number of times basic operation executed is: 10
Time complexity table is:
size    asc     rand    des
1       0       0       0
2       1       1       0
4       7       7       3
8       27      22      17
16      85      82      57
32      231     222     171
64      593     573     462
128     1459    1396    1167
256     3452    3317    2851
512     7958    7621    6692
1024    18060   17254   15384
2048    40204   38749   34926
4096    88835   85614   78209



Enter the number of elements: 16
Enter 16 elements:  1651 651 65 651 546 1 1 451 68 981 6516 0198 465 16 1 7846 1
Heap sorted array is:   1       1       1       16      65      68      198     451     465     546     651    651      981     1651    6516    7846
Number of times basic operation executed is: 85
Time complexity table is:
size    asc     rand    des
1       0       0       0
2       1       1       0
4       7       7       3
8       27      22      17
16      85      82      57
32      231     222     171
64      593     573     462
128     1459    1396    1167
256     3452    3317    2851
512     7958    7621    6692
1024    18060   17254   15384
2048    40204   38749   34926
4096    88835   85614   78209


*/

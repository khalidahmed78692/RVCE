#include <iostream>
using namespace std;

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right)
{
    int pivot = a[left], i = left + 1, j = right;
    while (1)
    {
        while (pivot >= a[i] && i <= right)
        {
            count++;
            i++;
        }
        while (pivot < a[j])
        {
            count++;
            j--;
        }
        if (i < j)
            swap(&a[i], &a[j]);
        else
        {
            swap(&a[left], &a[j]);
            return j;
        }
    }
}

void quick_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int s = partition(a, left, right);
        quick_sort(a, left, s - 1);
        quick_sort(a, s + 1, right);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n], i;
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    quick_sort(a, 0, n - 1);
    cout << "Quick sorted array is:";
    for (i = 0; i < n; i++)
        cout << "\t" << a[i];
    cout << "\nNumber of times basic operation executed is: " << count;
    cout << "\n\nTime complexity table is:\n";
    cout << "size\tasc\trand\trand\n";
    int c1, c2, j;
    for (i = 1; i <= 4096; i *= 2)
    {
        int a[i], r[i], d[i];
        for (j = 0; j < i; j++)
        {
            a[j] = j + 1;
            r[j] = rand() % i;
            d[j] = i - j;
        }
        count = 0;
        quick_sort(a, 0, i - 1);
        c1 = count;
        count = 0;
        quick_sort(r, 0, i - 1);
        c2 = count;
        count = 0;
        quick_sort(d, 0, i - 1);
        cout << i << "\t" << c1 << "\t" << c2 << "\t" << count << endl;
    }
}



/*

Output of the code:

Enter number of elements: 5
Enter 5 elements: 1 54 1 6546 1
Quick sorted array is:  1       1       1       54      6546
Number of times basic operation executed is: 6

Time complexity table is:
size    asc     rand    rand
1       0       0       0
2       1       1       1
4       6       4       6
8       28      20      28
16      120     46      120
32      496     149     496
64      2016    361     2016
128     8128    967     8128
256     32640   1867    32640
512     130816  5224    130816
1024    523776  11487   523776
2048    2096128 24438   2096128
4096    8386560 61932   8386560



Enter number of elements: 12
Enter 12 elements:  1968 651 84 981 657 2 4 94 54 91 6 4
Quick sorted array is:  2       4       4       6       54      84      91      94      651     657     981    1968
Number of times basic operation executed is: 46

Time complexity table is:
size    asc     rand    rand
1       0       0       0
2       1       1       1
4       6       4       6
8       28      20      28
16      120     46      120
32      496     149     496
64      2016    361     2016
128     8128    967     8128
256     32640   1867    32640
512     130816  5224    130816
1024    523776  11487   523776
2048    2096128 24438   2096128
4096    8386560 61932   8386560


*/

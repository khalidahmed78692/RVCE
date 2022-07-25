#include <iostream>
using namespace std;

int main()
{
    int i, j, u, l, n;
    cout << "Enter the upper and lower limits respectively of the array: ";
    cin >> u >> l;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n], D[u - l + 2], s[n];
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    // initialize the distribution values of all the unique elements to zero
    for (i = 0; i <= u - l; i++)
        D[i] = 0;
    // check the frequencies of the unique elements and place it in D matrix
    for (i = 0; i < n; i++)
        D[a[i] - l]++;
    // now except first element, add the frequencies of the current element and it's just previous element to get the Distribution values of the unique elements
    for (i = 1; i <= u - l; i++)
        D[i] += D[i-1];
    // now place the elements in to an array S, such that it is sorted
    for (i = n - 1; i >= 0; i--)
    {
        j = a[i] - l;
        s[D[j]-1] = a[i];
        D[j]--;
    }
    // print the sorted array
    cout << "The distribution count sorted array is:";
    for (i = 0; i < n; i++)
        cout << "\t" << s[i];
}

/*

Enter the upper and lower limits respectively of the array: 15 10
Enter the size of the array: 10
Enter 10 elements: 15 12 13 14 15 15 10 10 11 13   
The distribution count sorted array is: 10      10      11      12      13      13      14      15      15     15


Enter the upper and lower limits respectively of the array: 13 11
Enter the size of the array: 6
Enter 6 elements: 13 11 12 13 12 12
The distribution count sorted array is: 11      12      12      12      13      13


*/

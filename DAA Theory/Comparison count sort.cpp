#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n], s[n], count[n], i, j; // make to extra arrays, one for storing the count values and other for storing the elements in increasing order
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    // initialize every element count to 0
    for (i = 0; i < n; i++)
        count[i] = 0;
    // for every element, proper count values are assigned by proper comparison of the elements
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
    // now place the elements to another array S in increasing order
    for (i = 0; i < n; i++)
        s[count[i]] = a[i];
    cout << "The comparison count sorted array is:";
    for (i = 0; i < n; i++)
        cout << "\t" << s[i];
}

/*
Output of the code


Enter the size of the array: 8
Enter 8 elements: 1 646  56 4651 4 561 7 4   
The comparison count sorted array is:   1       4       4       7       56      561     646     4651


Enter the size of the array: 15
Enter 15 elements: 1 84 1 1 84 5 1 5 5 49 151  49 984 1 32
The comparison count sorted array is:   1       1       1       1       1       5       5       5       32     49       49      84      84      151     984


*/

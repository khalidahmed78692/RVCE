#include <iostream>
using namespace std;

int w[10], d;
bool x[10];

void sum_subset(int s, int k, int r)
{
    int i;
    static int b = 1;
    x[k] = true;
    if (s + w[k] == d)
    {
        cout << "Subset " << b++ << " :";
        for (i = 1; i <= k; i++)
            if (x[i])
                cout << "\t" << w[i];
        cout << endl;
    }
    else if (s + w[k + 1] <= d)
        sum_subset(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d))
    {
        x[k] = false;
        sum_subset(s, k + 1, r - w[k]);
    }
}

int main()
{
    int n, i, sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter elements in increasing order: ";
    for (i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    cout << "Enter the subset value that you want: ";
    cin >> d;
    if (sum < d || w[1] > d)
    {
        cout << "No solutions";
        exit(0);
    }
    sum_subset(0, 1, sum);
}

/*

Output of the code:

Enter the number of elements: 5
Enter elements in increasing order: 1 2 3 4 5
Enter the subset value that you want: 7
Subset 1 :      1       2       4
Subset 2 :      2       5        
Subset 3 :      3       4 

Enter the number of elements: 7
Enter elements in increasing order: 12 45 78 96 123 456 1024
Enter the subset value that you want: 456
Subset 1 :      456

Enter the number of elements: 10
Enter elements in increasing order: 1 2 3 4 5 6 7 8 9 10
Enter the subset value that you want: 15
Subset 1 :      1       2       3       4       5
Subset 2 :      1       2       3       9
Subset 3 :      1       2       4       8
Subset 4 :      1       2       5       7
Subset 5 :      1       3       4       7
Subset 6 :      1       3       5       6
Subset 7 :      1       5       9
Subset 8 :      1       6       8
Subset 9 :      2       3       4       6
Subset 10 :     2       4       9
Subset 11 :     2       5       8
Subset 12 :     2       6       7
Subset 13 :     3       4       8
Subset 14 :     3       5       7
Subset 15 :     4       5       6
Subset 16 :     6       9
Subset 17 :     7       8

*/

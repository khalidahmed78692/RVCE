#include <iostream>
using namespace std;

int w[100], d;
bool x[100];

void sum_subset(int s, int k, int r)
{
    static int b = 1;
    x[k] = true;
    if (s + w[k] == d)
    {
        cout << "Subset " << b++ << " :";
        for (int i = 1; i <= k; i++)
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

Enter the number of elements: 10
Enter elements in increasing order: 1 2 3 4 5 6 7 8 9 10
Enter the subset value that you want: 15
Subset 1 :      1       2       3       4       5
Subset 2 :      1       2       3       9        
Subset 3 :      1       2       4       8        
Subset 4 :      1       2       5       7        
Subset 5 :      1       3       4       7        
Subset 6 :      1       3       5       6        
Subset 7 :      1       4       10
Subset 8 :      1       5       9
Subset 9 :      1       6       8
Subset 10 :     2       3       4       6
Subset 11 :     2       3       10
Subset 12 :     2       4       9
Subset 13 :     2       5       8
Subset 14 :     2       6       7
Subset 15 :     3       4       8
Subset 16 :     3       5       7
Subset 17 :     4       5       6
Subset 18 :     5       10
Subset 19 :     6       9
Subset 20 :     7       8



Enter the number of elements: 5
Enter 5 elements: 4 8 78 140 153   
Enter the subset value: 200



Enter the number of elements: 6
Enter 6 elements: 12 45 78 89 96 99
Enter the subset value: 153
Subset 1 is:    12      45      96


*/

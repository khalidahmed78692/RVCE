#include <iostream>
using namespace std;

int x[20];

bool place(int k, int i)
{
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j]-i) == abs(j-k))
            return false;
    return true;
}

void printSolution(int n)
{
    int i, j;
    static int count = 1;
    cout << "\nSolution " << count++ << " is:\n";
    cout << "NQP|";
    for (i = 1; i <= n; i++)
        cout << "  " << i;
    cout << endl<<"____";
    for (i = 1; i < n; i++)
        cout << "____";
    for (i = 1; i <= n; i++)
    {
        cout << endl
             << i << "  |";
        for (j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "  Q";
            else
                cout << "  -";
        }
    }
    cout << endl;
}

void NQueen(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
                printSolution(n);
            else
                NQueen(k + 1, n);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    if (!n || n == 2 || n == 3)
        cout << "No solutions";
    else
        NQueen(1, n);
    return 0;
}

/*

Output of the code:

Enter the number of queens: 5

Solution 1 is:      
NQP|  1  2  3  4  5 
____________________
1  |  Q  -  -  -  - 
2  |  -  -  Q  -  - 
3  |  -  -  -  -  Q 
4  |  -  Q  -  -  - 
5  |  -  -  -  Q  - 

Solution 2 is:      
NQP|  1  2  3  4  5 
____________________
1  |  Q  -  -  -  - 
2  |  -  -  -  Q  -
3  |  -  Q  -  -  -
4  |  -  -  -  -  Q
5  |  -  -  Q  -  -

Solution 3 is:
NQP|  1  2  3  4  5
____________________
1  |  -  Q  -  -  -
2  |  -  -  -  Q  -
3  |  Q  -  -  -  -
4  |  -  -  Q  -  -
5  |  -  -  -  -  Q

Solution 4 is:
NQP|  1  2  3  4  5
____________________
1  |  -  Q  -  -  -
2  |  -  -  -  -  Q
3  |  -  -  Q  -  -
4  |  Q  -  -  -  -
5  |  -  -  -  Q  -

Solution 5 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  Q  -  -
2  |  Q  -  -  -  -
3  |  -  -  -  Q  -
4  |  -  Q  -  -  -
5  |  -  -  -  -  Q

Solution 6 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  Q  -  -
2  |  -  -  -  -  Q
3  |  -  Q  -  -  -
4  |  -  -  -  Q  -
5  |  Q  -  -  -  -

Solution 7 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  -  Q  -
2  |  Q  -  -  -  -
3  |  -  -  Q  -  -
4  |  -  -  -  -  Q
5  |  -  Q  -  -  -

Solution 8 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  -  Q  -
2  |  -  Q  -  -  -
3  |  -  -  -  -  Q
4  |  -  -  Q  -  -
5  |  Q  -  -  -  -

Solution 9 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  -  -  Q
2  |  -  Q  -  -  -
3  |  -  -  -  Q  -
4  |  Q  -  -  -  -
5  |  -  -  Q  -  -

Solution 10 is:
NQP|  1  2  3  4  5
____________________
1  |  -  -  -  -  Q
2  |  -  -  Q  -  -
3  |  Q  -  -  -  -
4  |  -  -  -  Q  -
5  |  -  Q  -  -  -





Enter the number of queens: 6

Solution 1 is:
NQP|  1  2  3  4  5  6  
________________________
1  |  -  Q  -  -  -  -  
2  |  -  -  -  Q  -  -  
3  |  -  -  -  -  -  Q  
4  |  Q  -  -  -  -  -  
5  |  -  -  Q  -  -  -  
6  |  -  -  -  -  Q  -  

Solution 2 is:
NQP|  1  2  3  4  5  6  
________________________
1  |  -  -  Q  -  -  -
2  |  -  -  -  -  -  Q
3  |  -  Q  -  -  -  -
4  |  -  -  -  -  Q  -
5  |  Q  -  -  -  -  -
6  |  -  -  -  Q  -  -

Solution 3 is:
NQP|  1  2  3  4  5  6
________________________
1  |  -  -  -  Q  -  -
2  |  Q  -  -  -  -  -
3  |  -  -  -  -  Q  -
4  |  -  Q  -  -  -  -
5  |  -  -  -  -  -  Q
6  |  -  -  Q  -  -  -

Solution 4 is:
NQP|  1  2  3  4  5  6
________________________
1  |  -  -  -  -  Q  -
2  |  -  -  Q  -  -  -
3  |  Q  -  -  -  -  -
4  |  -  -  -  -  -  Q
5  |  -  -  -  Q  -  -
6  |  -  Q  -  -  -  -

*/

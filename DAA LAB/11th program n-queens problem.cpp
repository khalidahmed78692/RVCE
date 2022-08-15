#include <iostream>
using namespace std;

bool isSafe(int **a, int x, int y, int n)
{
    // checking all the rows of the corresponding column
    for (int row = 0; row < x; row++)
        if (a[row][y])
            return false;
    int row = x, col = y;
    // checking all the upper left diagonals
    while (row >= 0 && col >= 0)
    {
        if (a[row][col])
            return false;
        row--;
        col--;
    }
    row = x, col = y;
    // checking all the upper right diagonals
    while (row >= 0 && col < n)
    {
        if (a[row][col])
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueens(int **a, int x, int n)
{
    // if we've placed all the queens safely then return true;
    if (x >= n)
        return true;
    // placing one by one all the queens
    for (int col = 0; col < n; col++)
    {
        if (isSafe(a, x, col, n)) // checking for a safe place
        {
            a[x][col] = 1;
            if (nQueens(a, x + 1, n)) // checking for next queen in next row
                return true;
            a[x][col] = 0; // backtracing step, if the place of the queen is not safe
        }
    }
    return false;
}

int main()
{
    int n, i, j;
    cout << "Enter the number of queens: ";
    cin >> n;
    if (n == 0 || n == 2 || n == 3)
    {
        cout << "No solution";
        exit(0);
    }
    int **a = new int *[n]; // create array using oops concept
    for (i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (j = 0; j < n; j++)
            a[i][j] = 0; // initialize all the array elements to 0
    }
    if (nQueens(a, 0, n)) // printing the possible arrangement if n-Queens has a solution
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                if (a[i][j])
                    cout << "Q ";
                else
                    cout << "- ";
            cout << endl;
        }
    }
    else
        cout << "No Solution";
    return 0;
}

/*

Output of the code:

Enter the number of queens: 4
- Q - - 
- - - Q 
Q - - - 
- - Q - 

Enter the number of queens: 16
Q - - - - - - - - - - - - - - - 
- - Q - - - - - - - - - - - - -
- - - - Q - - - - - - - - - - - 
- Q - - - - - - - - - - - - - -
- - - - - - - - - - - - Q - - - 
- - - - - - - - Q - - - - - - -
- - - - - - - - - - - - - Q - - 
- - - - - - - - - - - Q - - - - 
- - - - - - - - - - - - - - Q - 
- - - - - Q - - - - - - - - - - 
- - - - - - - - - - - - - - - Q
- - - - - - Q - - - - - - - - - 
- - - Q - - - - - - - - - - - - 
- - - - - - - - - - Q - - - - - 
- - - - - - - Q - - - - - - - - 
- - - - - - - - - Q - - - - - - 

*/

#include <iostream>
using namespace std;

int n, W, w[10], v[10], V[10][10], i, j, x[10];

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void Knapsack()
{
    for (i = 0; i <= n; i++)
    {
        cout << "\n"
             << i << " |\t";
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            cout << V[i][j] << "\t";
        }
    }
}

void FindingSolution()
{
    i = n, j = W;
    while (i != 0 || j != 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }
}

int main()
{
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the weight of the knapsack: ";
    cin >> W;
    cout << "Enter the weights of each objects: ";
    for (i = 1; i <= n; i++)
        cin >> w[i];
    cout << "Enter the profits of each objects: ";
    for (i = 1; i <= n; i++)
        cin >> v[i];
    cout << "The knapsack table is\n";
    cout << "V |\t";
    for (i = 0; i <= W; i++)
        cout << i << "\t";
    cout << endl;
    for (i = 0; i < W; i++)
        cout << "----------";
    Knapsack();
    FindingSolution();
    cout << "\nThe objects included in the solution are";
    cout << "\nObject\tweight\tProfit\n";
    for (i = 1; i <= n; i++)
        if (x[i])
            cout << i << "\t" << w[i] << "\t" << v[i] << endl;
    cout << "And maximum profit is: " << V[n][W];
}

/*
output of the code

Enter the number of objects: 4
Enter the weight of the knapsack: 5
Enter the weights of each objects: 2 1 3 2
Enter the profits of each objects: 8 6 16 11
The knapsack table is
V |     0       1       2       3       4       5
--------------------------------------------------
0 |     0       0       0       0       0       0
1 |     0       0       8       8       8       8
2 |     0       6       8       14      14      14
3 |     0       6       8       16      22      24
4 |     0       6       11      17      22      27
The objects included in the solution are
Object  weight  Profit
3       3       16
4       2       11
And maximum profit is: 27



Enter the number of objects: 3
Enter the weight of the knapsack: 5
Enter the weights of each objects: 2 3 2
Enter the profits of each objects: 5 10 8
The knapsack table is
V |     0       1       2       3       4       5
--------------------------------------------------
0 |     0       0       0       0       0       0
1 |     0       0       5       5       5       5
2 |     0       0       5       10      10      15
3 |     0       0       8       10      13      18
The objects included in the solution are
Object  weight  Profit
2       3       10
3       2       8
And maximum profit is: 18

*/

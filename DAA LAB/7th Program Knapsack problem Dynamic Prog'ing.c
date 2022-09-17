#include <stdio.h>

int n, W, w[10], v[10], V[10][10], x[10];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void Knapsack()
{
    for (int i = 0; i <= n; i++)
    {
        printf("\n%d |", i);
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            printf("\t%d", V[i][j]);
        }
    }
}

void KnowSolution()
{
    int i = n, j = W;
    while (i != 0 && j != 0)
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
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the weights of each objects: ");
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profits of each objects: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    printf("Enter the max capacity of the knapsack: ");
    scanf("%d", &W);
    printf("The KnapSack table is:\nV |");
    for (i = 0; i <= W; i++)
        printf("\t%d", i);
    printf("\n");
    for (i = 0; i <= n; i++)
        printf("----------");
    Knapsack();
    KnowSolution();
    printf("\n\nThe objects included in the knapsack are:\n");
    printf("Object\tWeight\tProfit\n");
    for (i = 0; i <= n; i++)
        if (x[i])
            printf("%d\t%d\t%d\n", i, w[i], v[i]);
    printf("\nThe max profit is: %d", V[n][W]);
}


/*
Output of the code:

Enter the number of objects: 4
Enter the weights of each objects: 2 1 3 2
Enter the profits of each objects: 8 6 16 11
Enter the max capacity of the knapsack: 5
The KnapSack table is:
V |     0       1       2       3       4       5
--------------------------------------------------
0 |     0       0       0       0       0       0
1 |     0       0       8       8       8       8
2 |     0       6       8       14      14      14
3 |     0       6       8       16      22      24
4 |     0       6       11      17      22      27

The objects included in the knapsack are:
Object  Weight  Profit
3       3       16
4       2       11

The max profit is: 27


Enter the number of objects: 3
Enter the weights of each objects: 2 3 2
Enter the profits of each objects: 5 10 8
Enter the max capacity of the knapsack: 5
The KnapSack table is:
V |     0       1       2       3       4       5
----------------------------------------
0 |     0       0       0       0       0       0
1 |     0       0       5       5       5       5
2 |     0       0       5       10      10      15
3 |     0       0       8       10      13      18

The objects included in the knapsack are:
Object  Weight  Profit
2       3       10
3       2       8

The max profit is: 18



*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int n, x[50], count = 1;

bool isSafe(int k, int i)
{
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    return true;
}

void printSolution()
{
    printf("\nSolution %d is:\n", count++);
    int i, j;
    printf("NQP|");
    for (i = 1; i <= n; i++)
        printf("  %d", i);
    printf("\n");
    for (i = 1; i <= n; i++)
        printf("____");
    for (i = 1; i <= n; i++)
    {
        printf("\n%d  |", i);
        for (j = 1; j <= n; j++)
            if (x[i] == j)
                printf("  Q");
            else
                printf("  -");
    }
    printf("\n");
}

void nQueen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (isSafe(k, i))
        {
            x[k]=i;
            if (k == n)
                printSolution();
            else
                nQueen(k + 1);
        }
    }
}

int main()
{
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (!n || n == 2 || n == 3)
        printf("No solution");
    else
        nQueen(1);
    return 0;
}

/*

Output of the code:

Enter the number of queens: 4

Solution 1 is:  
NQP|  1  2  3  4
________________
1  |  -  Q  -  -
2  |  -  -  -  Q
3  |  Q  -  -  -
4  |  -  -  Q  -

Solution 2 is:
NQP|  1  2  3  4
________________
1  |  -  -  Q  -
2  |  Q  -  -  -
3  |  -  -  -  Q
4  |  -  Q  -  -



Enter the number of queens: 7

Solution 1 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  Q  -  -  -  -  -  -
2  |  -  -  Q  -  -  -  -
3  |  -  -  -  -  Q  -  -
4  |  -  -  -  -  -  -  Q
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  Q  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 2 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  Q  -  -  -  -  -  -
2  |  -  -  -  Q  -  -  -
3  |  -  -  -  -  -  -  Q
4  |  -  -  Q  -  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  -  Q  -  -  -  -  -
7  |  -  -  -  -  Q  -  -

Solution 3 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  Q  -  -  -  -  -  -
2  |  -  -  -  -  Q  -  -
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  -  -  Q  -  -  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  -  Q  -  -  -

Solution 4 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  Q  -  -  -  -  -  -
2  |  -  -  -  -  -  Q  -
3  |  -  -  -  Q  -  -  -
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  -  -  -  Q  -  -
7  |  -  -  Q  -  -  -  -

Solution 5 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  Q  -  -  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  -  -  -  -  Q
5  |  -  -  -  -  Q  -  -
6  |  -  -  Q  -  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 6 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  Q  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  Q  -  -  -  -  -  -
5  |  -  -  Q  -  -  -  -
6  |  -  -  -  -  Q  -  -
7  |  -  -  -  -  -  -  Q

Solution 7 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  -  Q  -  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  -  Q  -  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  -  Q  -  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 8 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  -  Q  -  -
3  |  -  -  Q  -  -  -  -
4  |  Q  -  -  -  -  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  -  -  Q  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 9 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  -  Q  -  -
3  |  -  -  -  -  -  -  Q
4  |  -  -  -  Q  -  -  -
5  |  Q  -  -  -  -  -  -
6  |  -  -  Q  -  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 10 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  -  -  Q  -
3  |  -  -  Q  -  -  -  -
4  |  -  -  -  -  -  -  Q
5  |  -  -  -  Q  -  -  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  -  -  Q  -  -

Solution 11 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  Q  -  -  -  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  -  -  -  Q  -  -
4  |  -  -  Q  -  -  -  -
5  |  Q  -  -  -  -  -  -
6  |  -  -  -  -  -  Q  -
7  |  -  -  -  Q  -  -  -

Solution 12 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  -  Q  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  -  Q  -  -  -

Solution 13 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  -  -  -  Q  -  -  -
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  -  -  Q  -  -

Solution 14 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  -  -  -  -  Q  -  -
3  |  -  -  -  -  -  -  Q
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  Q  -  -  -
6  |  -  -  -  -  -  Q  -
7  |  Q  -  -  -  -  -  -

Solution 15 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  -  -  -  -  -  Q  -
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  -  Q  -  -
5  |  Q  -  -  -  -  -  -
6  |  -  -  -  Q  -  -  -
7  |  -  -  -  -  -  -  Q

Solution 16 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  Q  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  -  -  Q  -  -

Solution 17 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  Q  -  -  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  -  -  Q  -  -  -
4  |  Q  -  -  -  -  -  -
5  |  -  -  -  -  Q  -  -
6  |  -  Q  -  -  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 18 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  Q  -  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  -  -  Q  -  -

Solution 19 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  -  -  Q  -  -
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  -  -  Q  -  -  -  -
7  |  -  -  -  -  -  -  Q

Solution 20 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  -  Q  -  -  -  -  -
3  |  -  -  -  -  -  -  Q
4  |  -  -  -  -  Q  -  -
5  |  -  -  Q  -  -  -  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  -  -  -  Q  -

Solution 21 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  -  -  -  -  -  Q  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  Q  -  -  -  -
5  |  -  -  -  -  Q  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  Q  -  -  -  -  -

Solution 22 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  -  Q  -  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  -  Q  -  -
7  |  Q  -  -  -  -  -  -

Solution 23 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  Q  -  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  -  -  -  Q  -  -
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  Q  -  -  -  -

Solution 24 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  -  Q  -  -  -
4  |  -  -  -  -  -  -  Q
5  |  -  -  Q  -  -  -  -
6  |  -  -  -  -  -  Q  -
7  |  -  Q  -  -  -  -  -

Solution 25 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  -  -  -  Q  -  -  -
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  Q  -  -  -  -

Solution 26 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  -  Q  -  -  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  -  -  Q  -  -  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  -  -  Q  -  -  -
7  |  Q  -  -  -  -  -  -

Solution 27 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  -  -  Q  -  -  -  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  -  -  -  Q  -  -  -
6  |  -  Q  -  -  -  -  -
7  |  -  -  -  -  -  -  Q

Solution 28 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  Q  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  Q  -  -  -  -

Solution 29 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  Q  -  -
2  |  -  -  -  -  -  -  Q
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  -  -  Q  -  -  -  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  -  Q  -  -  -

Solution 30 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  Q  -  -  -  -  -  -
3  |  -  -  Q  -  -  -  -
4  |  -  -  -  -  Q  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  Q  -  -  -  -  -
7  |  -  -  -  Q  -  -  -

Solution 31 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  Q  -  -  -  -  -
3  |  -  -  -  -  Q  -  -
4  |  Q  -  -  -  -  -  -
5  |  -  -  -  Q  -  -  -
6  |  -  -  -  -  -  -  Q
7  |  -  -  Q  -  -  -  -

Solution 32 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  -  Q  -  -  -  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  -  Q  -  -  -
5  |  -  -  -  -  -  -  Q
6  |  -  -  -  -  Q  -  -
7  |  -  Q  -  -  -  -  -

Solution 33 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  -  Q  -  -  -  -
3  |  -  -  -  -  Q  -  -
4  |  -  -  -  -  -  -  Q
5  |  Q  -  -  -  -  -  -
6  |  -  -  -  Q  -  -  -
7  |  -  Q  -  -  -  -  -

Solution 34 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  -  Q  -  -  -  -
3  |  -  -  -  -  -  -  Q
4  |  -  -  -  Q  -  -  -
5  |  Q  -  -  -  -  -  -
6  |  -  -  -  -  Q  -  -
7  |  -  Q  -  -  -  -  -

Solution 35 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  -  -  Q  -  -  -
3  |  -  Q  -  -  -  -  -
4  |  -  -  -  -  -  -  Q
5  |  -  -  -  -  Q  -  -
6  |  -  -  Q  -  -  -  -
7  |  Q  -  -  -  -  -  -

Solution 36 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  Q  -
2  |  -  -  -  Q  -  -  -
3  |  -  -  -  -  -  -  Q
4  |  Q  -  -  -  -  -  -
5  |  -  -  Q  -  -  -  -
6  |  -  -  -  -  Q  -  -
7  |  -  Q  -  -  -  -  -

Solution 37 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  -  Q
2  |  -  Q  -  -  -  -  -
3  |  -  -  -  Q  -  -  -
4  |  -  -  -  -  -  Q  -
5  |  Q  -  -  -  -  -  -
6  |  -  -  Q  -  -  -  -
7  |  -  -  -  -  Q  -  -

Solution 38 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  -  Q
2  |  -  -  Q  -  -  -  -
3  |  -  -  -  -  -  Q  -
4  |  -  Q  -  -  -  -  -
5  |  -  -  -  -  Q  -  -
6  |  Q  -  -  -  -  -  -
7  |  -  -  -  Q  -  -  -

Solution 39 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  -  Q
2  |  -  -  -  Q  -  -  -
3  |  Q  -  -  -  -  -  -
4  |  -  -  -  -  Q  -  -
5  |  -  Q  -  -  -  -  -
6  |  -  -  -  -  -  Q  -
7  |  -  -  Q  -  -  -  -

Solution 40 is:
NQP|  1  2  3  4  5  6  7
____________________________
1  |  -  -  -  -  -  -  Q
2  |  -  -  -  -  Q  -  -
3  |  -  -  Q  -  -  -  -
4  |  Q  -  -  -  -  -  -
5  |  -  -  -  -  -  Q  -
6  |  -  -  -  Q  -  -  -
7  |  -  Q  -  -  -  -  -

*/
#include <stdio.h>
#include <stdbool.h>

int w[10], d, count = 1;
bool x[10];

void sumofsubset(int s, int k, int r)
{
    x[k] = true;
    if (s + w[k] == d)
    {
        printf("\nSubset %d:", count++);
        for (int i = 1; i <= k; i++)
            if (x[i])
                printf("\t%d", w[i]);
    }
    else if (s + w[k + 1] <= d)
        sumofsubset(s + w[k], k + 1, r - w[k]);
    if ((s + r - w[k] >= d) && (s + w[k + 1] <= d))
    {
        x[k] = false;
        sumofsubset(s, k + 1, r - w[k]);
    }
}

int main()
{
    int n, i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    printf("Enter the value of subset: ");
    scanf("%d", &d);
    printf("The subsets are:");
    sumofsubset(0, 1, sum);
    return 0;
}


/*
Output of the code:

Enter the number of elements: 5
Enter 5 elements: 1 2 3 4 5
Enter the value of subset: 7
The subsets are:
Subset 1:       1       2       4
Subset 2:       2       5        
Subset 3:       3       4 



Enter the number of elements: 8
Enter 8 elements: 12 45 78 89 90 91 93 100
Enter the value of subset: 326
The subsets are:
Subset 1:       12      45      78      91      100
Subset 2:       45      90      91      100

*/

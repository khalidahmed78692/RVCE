#include <iostream>
using namespace std;

int min(int i, int r)
{
    if (i > r)
        return r;
    else
        return i;
}

int bino_coeff(int n, int r)
{
    int c[n + 1][r + 1], m;
    for (int i = 0; i <= n; i++)
    {
        m = min(i, r);
        for (int j = 0; j <= m; j++)
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c[n][r];
}

int main()
{
    int n, r;
    cout << "For C(n,r), enter n and r respectively: ";
    cin >> n >> r;
    cout << n << "C" << r << " = " << bino_coeff(n, r);
}

/*

output of the code

For C(n,r), enter n and r respectively: 5 2
5C2 = 10

For C(n,r), enter n and r respectively: 12 6
12C6 = 924

*/

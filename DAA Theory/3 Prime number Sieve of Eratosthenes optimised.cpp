// Program to find the consecutive prime numbers from 2 to n using sieve of eratosthenes algo.

#include <iostream>
using namespace std;

int floorValOfRootN(int n)     // function to find the floor of root of n value
{
    int ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                ans = i;
                break;
            }
            else if ((i + 1) * (i + 1) > n)
            {
                ans = i;
                break;
            }
        }
    }
    return ans;
}

void SieveOfEratosthene(int n)
{
    int p, j, arr[n + 1];
    for (p = 2; p <= n; p++)
        arr[p] = p;
    int val = floorValOfRootN(n);
    for (p = 2; p <= val; p++)
    {
        if (arr[p] != 0)
            j = p * p;
        while (j <= n)
        {
            arr[j] = 0;
            j += p;
        }
    }
    int L[n];
    j = 0;
    for (p = 2; p <= n; p++)
        if (arr[p] != 0)
            L[j++] = arr[p];
    p = j;
    cout << "The prime numbers from 2 to " << n << " is:";
    for (j = 0; j < p; j++)
        cout << " " << L[j];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    SieveOfEratosthene(n);
}

/*

Output of the code:

Enter n: 25
The prime numbers from 2 to 25 is: 2 3 5 7 11 13 17 19 23


Enter n: 100
The prime numbers from 2 to 100 is: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97


Enter n: 250
The prime numbers from 2 to 250 is: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199 211 223 227 229 233 239 241

*/

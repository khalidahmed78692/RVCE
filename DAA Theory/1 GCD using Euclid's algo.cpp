#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{
    cout << "Enter two numbers: ";
    int m, n, r;
    cin >> m >> n;
    int num = gcd(m, n);
    cout << "GCD is: " << num;
}

/*

Output of the code:

Enter two numbers: 10 15
GCD is: 5


Enter two numbers: 13 12
GCD is: 1


Enter two numbers: 7 70
GCD is: 7


Enter two numbers: 1 5
GCD is: 1


Enter two numbers: 0 50
GCD is: 50


Enter two numbers: 78 123
GCD is: 3

*/

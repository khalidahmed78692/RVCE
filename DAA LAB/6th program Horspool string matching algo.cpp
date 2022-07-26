#include <iostream>
#include <string.h>
using namespace std;

#define size 256 // because there are 256 ASCII characters

int table[size];

void ShiftTable(char p[25])
{
    int m = strlen(p), i;
    for (i = 0; i < size; i++)
        table[i] = m;
    for (i = 0; i < m - 1; i++)
        table[p[i]] = m - 1 - i;
}

int Horspool(char t[100], char p[25])
{
    int m = strlen(p), n = strlen(t), i = m - 1, k;
    while (i < n)
    {
        k = 0;
        while ((k < m) && p[m - 1 - k] == t[i - k])
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table[t[i]];
    }
    return -1;
}

int main()
{
    char text[100], pattern[25];
    cout << "Enter the text: ";
    cin.getline(text, 100);
    cout << "Enter the pattern: ";
    cin.getline(pattern, 25);
    ShiftTable(pattern);
    int res = Horspool(text, pattern);
    if (res == -1)
        cout << "Pattern is not found in the text";
    else
        cout << "Pattern found at index " << res << " in the text";
}


/*

Enter the text: Khalid is learning Design and Analysis of Algorithm
Enter the pattern: Design and Analysis
Pattern found at index 19 in the text

Enter the text: aiwhgiqw4e0q    24i=0jmvkaigd6a5g651ads65f1gaga sdkf I'm gonna have food asdhfaiweji17  02938 @ 
Enter the pattern:  I'm gonna have food 
Pattern found at index 49 in the text


Enter the text: asgoiwuetq82459k vjaow rjtgoe8y2=3596ykefgafg9a/erty3564156521!$^%(^&#$%^@#4tdf54e6df4ga6de
Enter the pattern: dlsjogqiw90418=694emglvs
Pattern is not found in the text


*/

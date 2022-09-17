#include <stdio.h>
#include <string.h>

#define size 256

int table[size];

void shiftTable(char pattern[])
{
    int i, m = strlen(pattern);
    for (i = 0; i < size; i++)
        table[i] = m;
    for (i = 0; i < m - 1; i++)
        table[pattern[i]] = m - 1 - i;
}

int Horspool(char t[], char p[])
{
    int n = strlen(t), m = strlen(p), i, k;
    i = m - 1;
    while (i < n)
    {
        k = 0;
        while (k < m && (p[m - 1 - k] == t[i - k]))
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
    char text[100], pattern[25], temp;
    printf("Enter the text: ");
    scanf("%[^\n]s ", text); // text can include even white spaces
    fflush(stdin);           // used to not include '\n' in the pattern, it flushed the previous input from the user
    printf("Enter the pattern: ");
    scanf("%[^\n]s", pattern); // pattern can also include even white spaces
    printf("pattern is: %s", pattern);
    printf("|pattern ended before pipe or vertical bar\n");
    shiftTable(pattern);
    int res = Horspool(text, pattern);
    if (res == -1)
        printf("Match not found");
    else
        printf("Match found and it's at index: %d", res);
}


/*
Output of the code:

Enter the text: asldhgoasmngvka    apnsgpaj ^&)%&)( 7904029dbadkasog  
Enter the pattern:   apnsgpaj 
pattern is:   apnsgpaj |pattern ended before pipe or vertical bar
Match found and it's at index: 17



Enter the text: Hi this is 6th program of DAA LAB
Enter the pattern:  6th program
pattern is:  6th program|pattern ended before pipe or vertical bar
Match found and it's at index: 10




Enter the text: asgoahdsgajd;pajer
Enter the pattern: akdgoadhg
pattern is: akdgoadhg|pattern ended before pipe or vertical bar
Match not found


*/

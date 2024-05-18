#include <stdio.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)

void print_lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int lcs_length = L[m][n];

    char lcs[lcs_length + 1]; 
    lcs[lcs_length] = '\0';

    i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[--lcs_length] = X[i - 1];
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    print_lcs(X, Y, m, n);

    return 0;
}

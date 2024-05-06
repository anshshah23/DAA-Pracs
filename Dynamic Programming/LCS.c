#include <stdio.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)

int lcs_length(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    // Building the L[m+1][n+1] matrix in bottom-up manner
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains the length of LCS
    return L[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of Longest Common Subsequence: %d\n", lcs_length(X, Y, m, n));

    return 0;
}

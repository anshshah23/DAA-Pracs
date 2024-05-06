#include<stdio.h>
#include<limits.h>

#define N 100

// Function to find the minimum number of scalar multiplications needed to
// multiply the matrix chain [i...j] of size n
int matrixChainOrder(int p[], int n) {
    // m[i][j] = Minimum number of scalar multiplications needed to
    // multiply the matrix chain [i...j] of size n
    int m[n][n];

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // `L` is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // cost = cost/scalar multiplications
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    // Return the minimum number of scalar multiplications needed to multiply the matrix chain
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[N];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Minimum number of scalar multiplications needed: %d\n", matrixChainOrder(p, n + 1));

    return 0;
}

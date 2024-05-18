#include<stdio.h>

#define max(a, b) ((a > b) ? a : b)

int knapSack(int W, int wt[], int pf[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    printf("Intermediate outputs:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w) {
                int include = pf[i - 1] + K[i - 1][w - wt[i - 1]];
                int exclude = K[i - 1][w];
                K[i][w] = max(include, exclude);
                if (include > exclude)
                    printf("Using item %d (Weight = %d, Profit = %d), ", i, wt[i - 1], pf[i - 1]);
                else
                    printf("Not using item %d, ", i);
            } else
                K[i][w] = K[i - 1][w];
            printf("K[%d][%d] = %d\n", i, w, K[i][w]);
        }
    }
}

int main() {
    int pf[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(pf) / sizeof(pf[0]);

    printf("Maximum value that can be obtained: %d\n", knapSack(W, wt, pf, n));

    return 0;
}

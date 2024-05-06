#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed to make a given amount
int minCoins(int coins[], int n, int amount) {
    // Create a table to store results of subproblems. table[i] will be storing the minimum number of coins required for amount i
    int table[amount + 1];
    
    // Base case (If amount is 0, then 0 coins are needed)
    table[0] = 0;
    
    // Initialize all table values as INT_MAX
    for (int i = 1; i <= amount; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all values from 1 to amount
    for (int i = 1; i <= amount; i++) {
        // Go through all coins smaller than i
        for (int j = 0; j < n; j++)
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    return table[amount];
}

// Driver function
int main() {
    int coins[] = {1, 3, 5, 7};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);
    printf("Minimum number of coins required to make %d: %d\n", amount, minCoins(coins, n, amount));
    return 0;
}

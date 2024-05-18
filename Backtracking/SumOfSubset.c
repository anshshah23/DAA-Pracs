#include <stdio.h>

#define MAX_SIZE 100

int solution[MAX_SIZE];
int sum;
int count;

void findSubsetSum(int arr[], int n, int target, int index) {
    if (target == 0) {
        printf("Subset %d: ", ++count);
        for (int i = 0; i < index; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }

    if (target < 0 || index >= n) {
        return;
    }

    solution[index] = arr[index];
    findSubsetSum(arr, n, target - arr[index], index + 1);

    solution[index] = 0;
    findSubsetSum(arr, n, target, index + 1);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    count = 0;
    findSubsetSum(arr, n, sum, 0);

    return 0;
}
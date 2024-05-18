#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int a[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = 0; j < n-i-1 ; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    selectionSort(arr, n);
    end_time = clock(); 

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}

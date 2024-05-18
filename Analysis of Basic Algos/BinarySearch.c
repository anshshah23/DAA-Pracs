#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bs(int a[], int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2; 
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1; 
    }
    return -1;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int arr[1000000];
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 999999;

    for (int i = 0; i < n; ++i) {
        arr[i] = i; 
    }

    start = clock(); 
    int result = bs(arr, 0, n - 1, x);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
    if (result == -1)
        printf("Element not found\n"); 
    else
        printf("Element found at index %d\n", result);

    printf("Time taken: %f seconds\n", cpu_time_used); 

    printf("//Ansh Shah- 60004220082- C013"); 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qs(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pi = i + 1; 

        qs(a, low, pi - 1);
        qs(a, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int arr[1000000]; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000000;
    }

    start = clock();

    qs(arr, 0, n - 1);

    end = clock(); 

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", cpu_time_used);

    printf("//Ansh Shah- 60004220082- C013");
    return 0;
}
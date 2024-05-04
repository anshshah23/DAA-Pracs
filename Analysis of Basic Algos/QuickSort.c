#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qs(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high]; // Select the pivot element as the last element of the array
        int i = low - 1; // Initialize the index of the smaller element

        // Partition the array
        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Swap the pivot element with the element at the correct position
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pi = i + 1; // Get the index of the pivot element

        // Recursively sort the sub-arrays
        qs(a, low, pi - 1);
        qs(a, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int arr[1000000]; // Declare an array of size 1000000
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Generate random numbers and store them in the array
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000000;
    }

    start = clock(); // Start the clock

    // Call the quicksort function to sort the array
    qs(arr, 0, n - 1);

    end = clock(); // Stop the clock

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the CPU time used

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken: %f seconds\n", cpu_time_used);

    printf("//Ansh Shah- 60004220082- C013"); // Print author information

    return 0;
}
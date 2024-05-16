#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This code calculates the middle index of the array and performs binary search to find the element x.
// It returns the index of the element if found, otherwise -1.

int bs(int a[], int l, int r, int x) {
    while (l <= r) {
        int m = (l + r) / 2; // Calculate the middle index of the array
        if (a[m] == x) return m; // If the middle element is equal to x, return the index
        if (a[m] < x) l = m + 1; // If the middle element is less than x, search in the right half of the array
        else r = m - 1; // If the middle element is greater than x, search in the left half of the array
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int arr[1000000]; // Declare an array of size 1000000
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int x = 999999; // Element to be searched

    for (int i = 0; i < n; ++i) {
        arr[i] = i; // Initialize the array with values from 0 to n-1
    }

    start = clock(); // Start the timer
    int result = bs(arr, 0, n - 1, x); // Perform binary search on the array
    end = clock(); // Stop the timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the CPU time used

    if (result == -1)
        printf("Element not found\n"); // Print a message if the element is not found
    else
        printf("Element found at index %d\n", result); // Print the index of the element if found

    printf("Time taken: %f seconds\n", cpu_time_used); // Print the CPU time taken

    printf("//Ansh Shah- 60004220082- C013"); // Print author information
    return 0;
}

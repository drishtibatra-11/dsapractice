#include <stdio.h>

void countingSort(int arr[], int n) {
    int i;

    // Find maximum element
    int max = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Create count array
    int count[max + 1];

    // Initialize count array with 0
    for(i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store frequency of elements
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Compute prefix sums
    for(i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create output array
    int output[n];

    // Build output array
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy output to original array
    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
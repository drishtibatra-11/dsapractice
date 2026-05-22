#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto Partition Function
int partition(int arr[], int low, int high) {

    // Choose last element as pivot
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++) {

        // If current element is smaller than pivot
        if(arr[j] < pivot) {

            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot at correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) {

    if(low < high) {

        // Find partition index
        int pi = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pi - 1);

        // Sort right part
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call quick sort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
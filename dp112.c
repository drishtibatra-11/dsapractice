#include <stdio.h>

// Merge two sorted halves
void merge(int arr[], int low, int mid, int high) {

    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    // Compare elements and store smaller one
    while(i <= mid && j <= high) {

        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half
    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while(j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for(i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// Merge Sort function
void mergeSort(int arr[], int low, int high) {

    if(low < high) {

        int mid = (low + high) / 2;

        // Sort left half
        mergeSort(arr, low, mid);

        // Sort right half
        mergeSort(arr, mid + 1, high);

        // Merge sorted halves
        merge(arr, low, mid, high);
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

    // Call merge sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    printf("Sorted array:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
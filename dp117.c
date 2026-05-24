#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int inv_count = 0;

    // Merge two subarrays
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            
            // Count inversions
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements
    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if(left < right) {
        mid = (left + right) / 2;

        // Left subarray inversions
        inv_count += mergeSort(arr, temp, left, mid);

        // Right subarray inversions
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge inversions
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter array elements:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %d\n", inversions);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to sort individual buckets using insertion sort
void insertionSort(float bucket[], int n) {
    int i, j;
    float key;

    for(i = 1; i < n; i++) {
        key = bucket[i];
        j = i - 1;

        while(j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main() {
    int n, i, j, k = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements between 0 and 1:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create buckets
    float bucket[MAX][MAX];
    int count[MAX] = {0};

    // Put array elements into buckets
    for(i = 0; i < n; i++) {
        int bi = n * arr[i];
        bucket[bi][count[bi]] = arr[i];
        count[bi]++;
    }

    // Sort individual buckets
    for(i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    // Concatenate all buckets into arr[]
    for(i = 0; i < n; i++) {
        for(j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Print sorted array
    printf("Sorted array:\n");

    for(i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
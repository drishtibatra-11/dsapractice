#include <stdio.h>

int isMinHeap(int arr[], int n) {
    // Check all parent nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Left child
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            return 0;

        // Right child
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, N))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
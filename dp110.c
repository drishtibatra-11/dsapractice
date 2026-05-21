#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++) {

        // If one book has more pages than maxPages
        if(arr[i] > maxPages)
            return 0;

        // Add book to current student
        if(pages + arr[i] <= maxPages) {
            pages += arr[i];
        }
        else {
            // Allocate to next student
            students++;
            pages = arr[i];

            // If students exceed m
            if(students > m)
                return 0;
        }
    }

    return 1;
}

int allocateBooks(int arr[], int n, int m) {

    int low = arr[0];
    int high = 0;

    // Find maximum element and total sum
    for(int i = 0; i < n; i++) {

        if(arr[i] > low)
            low = arr[i];

        high += arr[i];
    }

    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", allocateBooks(arr, n, m));

    return 0;
}
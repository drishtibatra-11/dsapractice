#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {

    int painters = 1;
    int time = 0;

    for(int i = 0; i < n; i++) {

        // If one board itself exceeds maxTime
        if(arr[i] > maxTime)
            return 0;

        // Assign board to current painter
        if(time + arr[i] <= maxTime) {
            time += arr[i];
        }
        else {

            // Assign to next painter
            painters++;
            time = arr[i];

            // More painters needed
            if(painters > k)
                return 0;
        }
    }

    return 1;
}

int minTime(int arr[], int n, int k) {

    int low = arr[0];
    int high = 0;

    // Find maximum board length and total sum
    for(int i = 0; i < n; i++) {

        if(arr[i] > low)
            low = arr[i];

        high += arr[i];
    }

    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(isPossible(arr, n, k, mid)) {
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

    int n, k;

    scanf("%d %d", &n, &k);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", minTime(arr, n, k));

    return 0;
}
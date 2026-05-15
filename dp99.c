#include <stdio.h>

int maxLen(int arr[], int n) {
    int maxLength = 0;

    // Check all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            // If sum becomes 0
            if (sum == 0) {
                int length = j - i + 1;

                if (length > maxLength)
                    maxLength = length;
            }
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
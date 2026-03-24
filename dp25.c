#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000  // adjust if needed

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0, count = 0;

    // Simple hashmap using array (for small range)
    int hash[2 * SIZE + 1] = {0};
    int offset = SIZE;

    // To handle prefix sum = 0
    hash[offset] = 1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (hash[prefix + offset] > 0) {
            count += hash[prefix + offset];
        }

        hash[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}
#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    // Input sizes
    printf("Enter m: ");
    scanf("%d", &m);

    int nums1[m + 100];   // extra space for safety

    printf("Enter elements of nums1: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter n: ");
    scanf("%d", &n);

    int nums2[n];

    printf("Enter elements of nums2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Fill remaining with 0 (optional)
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    merge(nums1, m, nums2, n);

    // Output
    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n, val;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter value to remove: ");
    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    printf("Array after removing value:\n");
    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\nNumber of elements left = %d", k);

    return 0;
}
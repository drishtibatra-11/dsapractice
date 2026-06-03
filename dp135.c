#include <stdio.h>

int trap(int height[], int n) {
    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left < right) {

        if(height[left] < height[right]) {

            if(height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        }
        else {

            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}

int main() {
    int height[] = {4,2,0,3,2,5};
    int n = sizeof(height) / sizeof(height[0]);

    printf("Water Trapped = %d\n", trap(height, n));

    return 0;
}
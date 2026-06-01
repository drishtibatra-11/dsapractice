#include <stdio.h>

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = 4;

    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                printf("%d -> %d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }

        if(!found)
            printf("%d -> -1\n", arr[i]);
    }

    return 0;
}
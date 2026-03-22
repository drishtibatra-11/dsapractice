#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    
    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Flag to check identity
    int isIdentity = 1;  // assume true

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && matrix[i][j] != 1) {
                isIdentity = 0;  // diagonal must be 1
                break;
            } else if(i != j && matrix[i][j] != 0) {
                isIdentity = 0;  // non-diagonal must be 0
                break;
            }
        }
        if(!isIdentity) break; // early exit
    }

    if(isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
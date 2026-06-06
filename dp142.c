#include <stdio.h>
#include <stdlib.h>

void asteroidCollision(int asteroids[], int n) {
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        int curr = asteroids[i];
        int alive = 1;

        while (alive && top >= 0 &&
               stack[top] > 0 &&
               curr < 0) {

            if (abs(stack[top]) < abs(curr)) {
                top--;  // stack asteroid explodes
            }
            else if (abs(stack[top]) == abs(curr)) {
                top--;  // both explode
                alive = 0;
            }
            else {
                alive = 0; // current asteroid explodes
            }
        }

        if (alive) {
            stack[++top] = curr;
        }
    }

    printf("Remaining Asteroids: ");

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main() {
    int asteroids[] = {5, 10, -5};
    int n = sizeof(asteroids) / sizeof(asteroids[0]);

    asteroidCollision(asteroids, n);

    return 0;
}
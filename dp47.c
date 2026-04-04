#include <stdio.h>
#define MAX 100

int main() {
    int n, m;
    int arr[MAX];
    int front = 0, rear = -1, size = 0;

    // Input n
    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    // Input m (dequeue operations)
    scanf("%d", &m);

    // Perform m dequeues + circular enqueue (rotation)
    for (int i = 0; i < m; i++) {
        if (size == 0) break;

        int val = arr[front];              // remove front
        front = (front + 1) % MAX;
        size--;

        // insert back (circular rotation)
        rear = (rear + 1) % MAX;
        arr[rear] = val;
        size++;
    }

    // Print queue from front to rear
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[(front + i) % MAX]);
    }

    return 0;
}
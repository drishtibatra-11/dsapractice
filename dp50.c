#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return (rear == MAX - 1);
}

// Push Front
void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front > 0) {
        front--;
    } else {
        printf("No space at front\n");
        return;
    }

    deque[front] = x;
}

// Push Back
void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// Pop Front
int pop_front() {
    if (isEmpty()) return -1;

    int val = deque[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return val;
}

// Pop Back
int pop_back() {
    if (isEmpty()) return -1;

    int val = deque[rear];

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }

    return val;
}

// Get Front
int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

// Get Back
int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

// Size
int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

// Reverse
void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

// Sort (Ascending)
void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x; scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x; scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        }
        else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        }
        else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        }
        else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(op, "sort") == 0) {
            sort();
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

/* Compare intervals by start time */
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

/* Function to merge intervals */
void mergeIntervals(Interval arr[], int n) {
    if (n <= 0)
        return;

    /* Sort intervals */
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int index = 0;

    result[index] = arr[0];

    for (int i = 1; i < n; i++) {

        /* If overlapping */
        if (arr[i].start <= result[index].end) {

            /* Update end time */
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        }
        else {
            /* Non-overlapping interval */
            index++;
            result[index] = arr[i];
        }
    }

    /* Print merged intervals */
    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    mergeIntervals(arr, n);

    return 0;
}
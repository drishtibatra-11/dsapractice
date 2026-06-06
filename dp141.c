#include <stdio.h>

#define MAX 1000

int maxHeap[MAX], maxSize = 0;
int minHeap[MAX], minSize = 0;

/* ---------- Max Heap ---------- */

void maxHeapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;

        if (maxHeap[p] >= maxHeap[i])
            break;

        int temp = maxHeap[p];
        maxHeap[p] = maxHeap[i];
        maxHeap[i] = temp;

        i = p;
    }
}

void insertMax(int val) {
    maxHeap[maxSize] = val;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void maxHeapifyDown(int i) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < maxSize && maxHeap[l] > maxHeap[largest])
            largest = l;

        if (r < maxSize && maxHeap[r] > maxHeap[largest])
            largest = r;

        if (largest == i)
            break;

        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        i = largest;
    }
}

int extractMax() {
    int root = maxHeap[0];

    maxHeap[0] = maxHeap[maxSize - 1];
    maxSize--;

    maxHeapifyDown(0);

    return root;
}

/* ---------- Min Heap ---------- */

void minHeapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;

        if (minHeap[p] <= minHeap[i])
            break;

        int temp = minHeap[p];
        minHeap[p] = minHeap[i];
        minHeap[i] = temp;

        i = p;
    }
}

void insertMin(int val) {
    minHeap[minSize] = val;
    minHeapifyUp(minSize);
    minSize++;
}

void minHeapifyDown(int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < minSize && minHeap[l] < minHeap[smallest])
            smallest = l;

        if (r < minSize && minHeap[r] < minHeap[smallest])
            smallest = r;

        if (smallest == i)
            break;

        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        i = smallest;
    }
}

int extractMin() {
    int root = minHeap[0];

    minHeap[0] = minHeap[minSize - 1];
    minSize--;

    minHeapifyDown(0);

    return root;
}

/* ---------- Median Finder ---------- */

void addNum(int num) {

    if (maxSize == 0 || num <= maxHeap[0])
        insertMax(num);
    else
        insertMin(num);

    if (maxSize > minSize + 1)
        insertMin(extractMax());

    else if (minSize > maxSize + 1)
        insertMax(extractMin());
}

double findMedian() {

    if (maxSize == minSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;

    if (maxSize > minSize)
        return maxHeap[0];

    return minHeap[0];
}

int main() {

    addNum(5);
    addNum(15);
    addNum(1);
    addNum(3);

    printf("Median = %.1f\n", findMedian());

    return 0;
}
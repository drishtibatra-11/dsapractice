#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to compare intervals for sorting
int compare(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    return x[0] - y[0];
}

// Min Heap functions
void heapifyUp(int heap[], int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            index = parent;
        }
        else
            break;
    }
}

void heapifyDown(int heap[], int size, int index)
{
    while(1)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;

            index = smallest;
        }
        else
            break;
    }
}

void insertHeap(int heap[], int *size, int value)
{
    heap[*size] = value;
    (*size)++;

    heapifyUp(heap, (*size) - 1);
}

void deleteMin(int heap[], int *size)
{
    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);
}

int main()
{
    int n, i;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int meetings[MAX][2];

    printf("Enter start and end times:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &meetings[i][0], &meetings[i][1]);
    }

    // Sort meetings by start time
    qsort(meetings, n, sizeof(meetings[0]), compare);

    int heap[MAX];
    int heapSize = 0;

    // Add first meeting end time
    insertHeap(heap, &heapSize, meetings[0][1]);

    // Process remaining meetings
    for(i = 1; i < n; i++)
    {
        int start = meetings[i][0];
        int end = meetings[i][1];

        // Reuse room if earliest meeting finished
        if(start >= heap[0])
        {
            deleteMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, end);
    }

    printf("Minimum rooms required = %d\n", heapSize);

    return 0;
}
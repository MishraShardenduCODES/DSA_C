#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int heap[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

MaxHeap* createMaxHeap() {
    MaxHeap* maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->size = 0;
    return maxHeap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap* maxHeap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < maxHeap->size && maxHeap->heap[left] > maxHeap->heap[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->heap[right] > maxHeap->heap[largest])
        largest = right;

    if (largest != index) {
        swap(&maxHeap->heap[index], &maxHeap->heap[largest]);
        maxHeapify(maxHeap, largest);
    }
}

void insert(MaxHeap* maxHeap, int value) {
    if (maxHeap->size >= MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    maxHeap->heap[maxHeap->size++] = value;
    int i = maxHeap->size - 1;
    while (i > 0 && maxHeap->heap[(i - 1) / 2] < maxHeap->heap[i]) {
        swap(&maxHeap->heap[i], &maxHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap is empty. Cannot extract max.\n");
        return -1;
    }

    int max = maxHeap->heap[0];
    maxHeap->heap[0] = maxHeap->heap[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return max;
}

void removeMax(MaxHeap* maxHeap) {
    extractMax(maxHeap);
}

int main() {
    MaxHeap* maxHeap = createMaxHeap();

    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    insert(maxHeap, 40);

    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d ", maxHeap->heap[i]);
    printf("\n");

    printf("Extracted Max: %d\n", extractMax(maxHeap));

    printf("Max Heap after extraction: ");
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d ", maxHeap->heap[i]);
    printf("\n");

    return 0;
}

#include <stdio.h>

#define MAX 100000

// Max Heap (for left half)
int maxHeap[MAX], maxSize = 0;

// Min Heap (for right half)
int minHeap[MAX], minSize = 0;

// ---------- MAX HEAP ----------
void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[(i - 1) / 2];   //swap parent and current
        maxHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < maxSize && maxHeap[l] > maxHeap[largest]) largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest]) largest = r;

    if (largest != i) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;
        maxHeapifyDown(largest);
    }
}

void insertMax(int x) {
    maxHeap[maxSize++] = x;
    maxHeapifyUp(maxSize - 1);
}

int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}

// ---------- MIN HEAP ----------
void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void minHeapifyDown(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < minSize && minHeap[l] < minHeap[smallest]) smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest]) smallest = r;

    if (smallest != i) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;
        minHeapifyDown(smallest);
    }
}

void insertMin(int x) {
    minHeap[minSize++] = x;
    minHeapifyUp(minSize - 1);
}

int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}

// ---------- MAIN ----------
int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (maxSize == 0 || x <= maxHeap[0])
            insertMax(x);
        else
            insertMin(x);

        // Balance heaps
        if (maxSize > minSize + 1)
            insertMin(extractMax());
        else if (minSize > maxSize)
            insertMax(extractMin());

        // Print median
        if (maxSize == minSize)
            printf("%.1f ", (maxHeap[0] + minHeap[0]) / 2.0);
        else
            printf("%.1f ", (float)maxHeap[0]);
    }
    return 0;
}
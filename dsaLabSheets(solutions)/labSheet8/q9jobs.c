#include <stdio.h>

#define MAX 100000

int heap[MAX], size = 0;

// Min Heap (stores rewards)
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        int t = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = t;
        heapifyDown(smallest);
    }
}

void insert(int x) {
    heap[size++] = x;
    heapifyUp(size-1);
}

int extractMin() {
    int root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Simple sort by deadline (bubble sort for lab simplicity)
void sort(int d[], int r[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (d[j] > d[j+1]) {
                int td = d[j]; d[j] = d[j+1]; d[j+1] = td;
                int tr = r[j]; r[j] = r[j+1]; r[j+1] = tr;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int d[n], r[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &d[i], &r[i]);

    sort(d, r, n);

    for (int i = 0; i < n; i++) {
        insert(r[i]);

        if (size > d[i])
            extractMin();
    }

    int total = 0;
    for (int i = 0; i < size; i++)
        total += heap[i];

    printf("%d\n", total);
    return 0;
}
#include <stdio.h>

#define MAX 100000

int heap[MAX], size = 0;

// Min Heap
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

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    int cost = 0;

    while (size > 1) {
        int a = extractMin();
        int b = extractMin();
        int sum = a + b;

        cost += sum;
        insert(sum);
    }

    printf("%d\n", cost);
    return 0;
}
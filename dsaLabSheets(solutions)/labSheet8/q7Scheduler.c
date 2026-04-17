#include <stdio.h>

#define MAX 1000

int heap[MAX], size = 0;

//max heap gives task with highest remaining frequency : hardest to schedule
//afterdoing 1 task you need k gap so in one cycle you can run k+1 different tasks(including original and idle)


// Max Heap
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l] > heap[largest]) largest = l;
    if (r < size && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapifyDown(largest);
    }
}

void insert(int x) {
    heap[size++] = x;
    heapifyUp(size - 1);
}

int extractMax() {
    int root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int freq[26] = {0};
    char c;

    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        freq[c - 'A']++;
    }

    // Build heap
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            insert(freq[i]);
    }

    int time = 0;

    while (size > 0) {
        int temp[100], t = 0;
        int cycle = k + 1;

        while (cycle-- && size > 0) {
            int f = extractMax();
            if (f - 1 > 0)
                temp[t++] = f - 1;
            time++;
        }

        for (int i = 0; i < t; i++)
            insert(temp[i]);

        if (size == 0)
            break;

        time += cycle + 1; // idle time
    }

    printf("%d\n", time);
    return 0;
}
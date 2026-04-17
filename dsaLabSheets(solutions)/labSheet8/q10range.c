#include <stdio.h>
#include <limits.h>

#define MAXK 100

typedef struct {
    int val, row, col;
} Node;

Node heap[MAXK];
int size = 0;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2].val > heap[i].val) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l].val < heap[smallest].val) smallest = l;
    if (r < size && heap[r].val < heap[smallest].val) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(Node x) {
    heap[size++] = x;
    heapifyUp(size-1);
}

Node extractMin() {
    Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

int main() {
    int k;
    scanf("%d", &k);

    int arr[100][100], sz[100];

    for (int i = 0; i < k; i++) {
        scanf("%d", &sz[i]);
        for (int j = 0; j < sz[i]; j++)
            scanf("%d", &arr[i][j]);
    }

    int max = INT_MIN;

    for (int i = 0; i < k; i++) {
        Node n = {arr[i][0], i, 0};
        insert(n);
        if (arr[i][0] > max) max = arr[i][0];
    }

    int start = 0, end = INT_MAX;

    while (1) {
        Node minNode = extractMin();
        int min = minNode.val;

        if (max - min < end - start) {
            start = min;
            end = max;
        }

        if (minNode.col + 1 == sz[minNode.row])
            break;

        int nextVal = arr[minNode.row][minNode.col + 1];
        Node next = {nextVal, minNode.row, minNode.col + 1};
        insert(next);

        if (nextVal > max) max = nextVal;
    }

    printf("%d %d\n", start, end);
    return 0;
}
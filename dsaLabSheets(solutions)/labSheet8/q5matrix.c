#include <stdio.h>

#define MAX 100

typedef struct {
    int val, row, col;
} Node;

Node heap[MAX];
int size = 0;

// Min Heap
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
    int n;
    scanf("%d", &n);

    int mat[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int k;
    scanf("%d", &k);

    // Insert first column
    for (int i = 0; i < n; i++) {
        Node x = {mat[i][0], i, 0};
        insert(x);
    }

    Node ans;

    for (int i = 0; i < k; i++) {
        ans = extractMin();

        if (ans.col + 1 < n) {
            Node next = {mat[ans.row][ans.col+1], ans.row, ans.col+1};
            insert(next);
        }
    }

    printf("%d\n", ans.val);
    return 0;
}
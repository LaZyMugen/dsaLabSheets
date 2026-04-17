#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* down;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

int main() {
    int V;
    scanf("%d", &V);

    int mat[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &mat[i][j]);

    Node* head = createNode(0);
    Node* currCol = head;

    for (int i = 1; i < V; i++) {
        currCol->down = createNode(i);
        currCol = currCol->down;
    }

    currCol = head;
    for (int i = 0; i < V; i++) {
        Node* temp = currCol;

        for (int j = 0; j < V; j++) {
            if (mat[i][j] == 1) {
                temp->right = createNode(j);
                temp = temp->right;
            }
        }
        currCol = currCol->down;
    }

    currCol = head;
    while (currCol) {
        Node* temp = currCol;
        printf("%d", temp->data);

        temp = temp->right;
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->right;
        }

        if (currCol->down) printf("\n|\n");
        currCol = currCol->down;
    }

    return 0;
}
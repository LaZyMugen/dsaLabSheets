#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    scanf("%d", &n);

    struct Node *head=NULL, *tail=NULL;
    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = v; t->next = NULL;
        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    scanf("%d", &x);

    struct Node *newH=NULL, *newT=NULL;
    int count = 0;

    while (head) {
        if (head->data == x)
            count++;
        else {
            if (!newH) newH = newT = head;
            else { newT->next = head; newT = head; }
        }
        head = head->next;
    }

    while (count--) {
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;
        if (!newH) newH = newT = t;
        else { newT->next = t; newT = t; }
    }

    while (newH) {
        printf("%d ", newH->data);
        newH = newH->next;
    }
    return 0;
}

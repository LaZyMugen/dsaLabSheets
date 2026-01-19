#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node dummy;
    dummy.next = NULL;
    struct Node* prev = &dummy;

    struct Node *head=NULL, *tail=NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;
        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    dummy.next = head;

    while (prev->next && prev->next->next) {
        struct Node* a = prev->next;
        struct Node* b = a->next;

        a->next = b->next;
        b->next = a;
        prev->next = b;

        prev = a;
    }

    head = dummy.next;
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}

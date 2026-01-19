#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head=NULL, *tail=NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;
        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    struct Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data <= curr->data) {
            struct Node* del = curr->next;
            curr->next = del->next;
            free(del);
        } else {
            curr = curr->next;
        }
    }

    curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    return 0;
}


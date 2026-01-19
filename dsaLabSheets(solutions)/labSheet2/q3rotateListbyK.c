#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head=NULL, *tail=NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x; t->next = NULL;
        if (!head) head = tail = t;
        else { tail->next = t; tail = t; }
    }

    scanf("%d", &k);
    if (!head || k == 0) return 0;

    int len = 1;
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    k %= len;
    if (k == 0) {
        temp = head;
    } else {
        temp->next = head;
        for (int i = 0; i < len - k; i++)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
    }

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}

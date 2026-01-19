#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *evenH=NULL, *evenT=NULL, *oddH=NULL, *oddT=NULL;

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = NULL;

        if (x % 2 == 0) {
            if (!evenH) evenH = evenT = t;
            else { evenT->next = t; evenT = t; }
        } else {
            if (!oddH) oddH = oddT = t;
            else { oddT->next = t; oddT = t; }
        }
    }

    if (evenT) evenT->next = oddH;
    struct Node* head = evenH ? evenH : oddH;

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}

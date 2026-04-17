// q11.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

long long res[MAX];
int sz = 0;

void compute(char *s, int l, int r) {
    int found = 0;

    for (int i = l; i <= r; i++) {
        if (s[i]=='+'||s[i]=='-'||s[i]=='*') {
            found = 1;

            int ls = sz;
            compute(s, l, i-1);
            int le = sz;

            int rs = sz;
            compute(s, i+1, r);
            int re = sz;

            long long temp[MAX];
            int t = 0;

            for (int x = ls; x < le; x++) {
                for (int y = rs; y < re; y++) {
                    if (s[i]=='+') temp[t++] = res[x] + res[y];
                    else if (s[i]=='-') temp[t++] = res[x] - res[y];
                    else temp[t++] = res[x] * res[y];
                }
            }

            sz = ls;
            for (int k = 0; k < t; k++) res[sz++] = temp[k];
        }
    }

    if (!found) {
        long long num = 0;
        for (int i = l; i <= r; i++)
            num = num*10 + (s[i]-'0');
        res[sz++] = num;
    }
}

int cmp(const void *a, const void *b) {
    long long x = *(long long*)a, y = *(long long*)b;
    return (x > y) - (x < y);
}

int main() {
    int n;
    char s[25];
    scanf("%d", &n);
    scanf("%s", s);

    compute(s, 0, n-1);

    qsort(res, sz, sizeof(long long), cmp);

    for (int i = 0; i < sz; i++)
        printf("%lld ", res[i]);
}
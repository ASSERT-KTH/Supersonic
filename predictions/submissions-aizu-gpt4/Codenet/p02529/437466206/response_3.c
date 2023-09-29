#include <stdio.h>
#include <stdbool.h>

#define MAX 10000
#define NIL -1

int search(int A[], int n, int key) {
    int i = 0;
    A[n] = key;
    while (A[i] != key) i++;
    return i != n;
}

int main() {
    int i, n, q, key, sum = 0;
    int S[MAX], T[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for (i = 0; i < q; i++) scanf("%d", &T[i]);
    for (i = 0; i < q; i++) {
        key = T[i];
        if (search(S, n, key)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
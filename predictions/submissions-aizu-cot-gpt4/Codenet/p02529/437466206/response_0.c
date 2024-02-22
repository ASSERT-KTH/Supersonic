#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int binary_search(int* A, int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return 1;
        if (key > A[mid]) left = mid + 1;
        else if (key < A[mid]) right = mid;
    }
    return 0;
}

int main() {
    int i, n, q, C = 0;
    scanf("%d", &n);
    int *S = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    std::sort(S, S + n);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (binary_search(S, n, t)) {
            C++;
        }
    }
    printf("%d\n", C);
    free(S);
    return 0;
}
#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int count = 0, n;

int main(void) {
    int S[500000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);
    mergesort(S, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d", S[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n%d\n", count);
    return 0;
}

void mergesort(int *S, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergesort(S, left, mid);
        mergesort(S, mid, right);
        merge(S, left, mid, right);
    }
}

void merge(int *S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int i = 0;
    int j = mid;
    int k = left;
    while (k < right) {
        if (S[j] > S[i])
            S[k++] = S[i++];
        else
            S[k++] = S[j++];
        if (i == mid) i = right;
        if (j == right) j = mid;
    }
    count += right - left;
}
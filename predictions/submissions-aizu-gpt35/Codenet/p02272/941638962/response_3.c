#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, int, int);
void merge(int *, int, int, int);
long long count = 0, n;
int *Left, *Right;

int main(void) {
    int *S;
    scanf("%lld", &n);
    S = (int*) malloc(n * sizeof(int));
    Left = (int*) malloc((n/2+2) * sizeof(int));
    Right = (int*) malloc((n/2+2) * sizeof(int));
    for (long long i = 0; i < n; i++)
        scanf("%d", &S[i]);
    mergesort(S, 0, n);
    for (long long i = 0; i < n; i++) {
        printf("%d", S[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n%lld\n", count);
    free(S);
    free(Left);
    free(Right);
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
    for (int i = 0; i < n1; i++)
        Left[i] = S[left + i];
    for (int i = 0; i < n2; i++)
        Right[i] = S[mid + i];
    Left[n1] = Right[n2] = 2147483647;
    int i = 0, j = 0, k = left;
    while (k < right) {
        if (Left[i] <= Right[j])
            S[k++] = Left[i++];
        else {
            S[k++] = Right[j++];
            count += n1 - i;
        }
    }
}
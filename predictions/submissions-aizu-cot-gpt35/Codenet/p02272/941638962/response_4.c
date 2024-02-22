#include <stdio.h>
#include <limits.h>

void mergesort(int *, int, int, int*);
void merge(int *, int, int, int, int*);

int main(void) {
    int n;
    scanf("%d", &n);

    int S[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    int count = 0;
    mergesort(S, 0, n, &count);

    for (int i = 0; i < n; i++) {
        printf("%d", S[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n%d\n", count);

    return 0;
}

void mergesort(int *S, int left, int right, int *count) {
    if (left + 1 < right) {
        int mid = (left + right) >> 1;
        mergesort(S, left, mid, count);
        mergesort(S, mid, right, count);
        merge(S, left, mid, right, count);
    }
}

void merge(int *S, int left, int mid, int right, int *count) {
    int n1 = mid - left;
    int n2 = right - mid;

    int Left[n1];
    int Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = S[left + i];
    for (int i = 0; i < n2; i++)
        Right[i] = S[mid + i];

    Left[n1] = Right[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    int k = left;

    while (k < right) {
        if (Left[j] > Right[i]) {
            S[k++] = Right[i++];
            *count += n1 - j;
        } else {
            S[k++] = Left[j++];
        }
    }
}
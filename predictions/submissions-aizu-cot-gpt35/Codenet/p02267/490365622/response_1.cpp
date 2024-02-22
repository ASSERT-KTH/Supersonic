#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

int main() {
    int n, *S, q, *T, i, cnt = 0;
    scanf("%d", &n);
    
    S = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &S[i]);

    scanf("%d", &q);
    T = (int*)malloc(q * sizeof(int));
    for (i = 0; i < q; i++)
        scanf("%d", &T[i]);

    qsort(S, n, sizeof(int), compare);

    for (i = 0; i < q; i++) {
        if (binarySearch(S, 0, n - 1, T[i]) != -1)
            cnt++;
    }

    printf("%d\n", cnt);

    free(S);
    free(T);

    return 0;
}
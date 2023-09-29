#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

bool search(int *arr, int n, int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return true;
        if (key > arr[mid])
            left = mid + 1;
        else if (key < arr[mid])
            right = mid;
    }
    return false;
}

int main() {
    int n, i, q, key, sum = 0;
    int S[MAX];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &S[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        if (search(S, n, key)) sum++;
    }
    printf("%d\n", sum);

    return 0;
}
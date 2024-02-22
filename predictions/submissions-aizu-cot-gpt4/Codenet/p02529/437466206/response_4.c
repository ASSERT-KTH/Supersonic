#include <stdio.h>
#include <algorithm>

int binary_search(int* array, int size, int key) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (array[mid] == key)
            return 1;
        else if (key < array[mid])
            right = mid;
        else 
            left = mid + 1;
    }
    return 0;
}

int main() {
    int n, q, C = 0, S[100], T[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    std::sort(S, S+n);

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < q; i++) {
        C += binary_search(S, n, T[i]);
    }
    printf("%d\n", C);
    return 0;
}
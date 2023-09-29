#include <stdio.h>
#include <stdbool.h>

bool binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    int n, S[10000], q, T[500], i, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &S[i]);
    scanf("%d", &q);
    for (i = 0; i < q; i++)
        scanf("%d", &T[i]);
    for (i = 0; i < q; i++) {
        if (binary_search(S, n, T[i])) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
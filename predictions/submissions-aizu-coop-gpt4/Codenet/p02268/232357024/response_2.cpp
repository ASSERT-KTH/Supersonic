#include <cstdio>
#include <algorithm>

// Function to perform binary search
bool binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }

    // Sort the array before performing binary search
    std::sort(S, S + n);

    int cnt = 0;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int T;
        scanf("%d", &T);
        // Perform binary search only if T is within the range of the array
        if (T >= S[0] && T <= S[n - 1] && binarySearch(S, 0, n - 1, T)) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
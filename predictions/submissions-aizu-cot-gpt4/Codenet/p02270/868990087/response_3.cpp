#include <cstdio>
using namespace std;

int check(int N[], int n, int k, int w) {
    int i = 0;
    for (int j = 0; j < k; ++j) {
        int s = 0;
        while (s + N[i] <= w) {
            s += N[i];
            ++i;
            if (i == n) return n;
        }
        if (s >= w) break; // breaking the loop here once we've found a valid group
    }
    return i;
}

int main() {
    int MAX_W = 1000000000;
    int n, k;
    scanf("%d %d", &n, &k);
    int *N = new int[n]; // dynamic memory allocation
    for (int i = 0; i < n; ++i) {
        scanf("%d", &N[i]);
    }
    int left = 0;
    int right = MAX_W;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(N, n, k, mid) >= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", right); // using printf instead of cout
    delete[] N; // free the allocated memory after use
    return 0;
}
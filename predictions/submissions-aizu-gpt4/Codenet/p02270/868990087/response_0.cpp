#include <cstdio>
#include <algorithm>

int n, k, w[100005];

bool check(int q) {
    int cnt = 0;
    for (int i = 0, j = 0; i < k; ++i) {
        int s = 0;
        while (j < n && s + w[j] <= q) {
            s += w[j++];
        }
        if(j == n) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    int left = *std::max_element(w, w+n);
    int right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(mid)) right = mid;
        else left = mid;
    }
    printf("%d\n", right);
    return 0;
}
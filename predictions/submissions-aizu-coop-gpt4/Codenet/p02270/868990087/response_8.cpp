#include <cstdio>
#include <vector>
using namespace std;

int check(vector<int>& N, int n, int k, int w) {
    int i = 0, s = 0;
    for (int j = 0; j < k; ++j) {
        while (i < n && s + N[i] <= w) {
            s += N[i++];
        }
        if (i == n)
            return n;
        s = 0;
    }
    return i;
}

int main() {
    int MAX_W = 1000000000;
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> N(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &N[i]);
    }
    int left = 0, right = MAX_W;
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(N, n, k, mid) == n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", right);
    return 0;
}
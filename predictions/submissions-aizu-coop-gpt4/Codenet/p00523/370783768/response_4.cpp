#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200000];

bool calc(int64 size) {
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < N; ++i) {
        while (j < 2*N && sum[j] < sum[i] + size) ++j;
        while (k < j && sum[k] < sum[i] + 2*size) ++k;
        while (l < k && sum[l] < sum[i] + 3*size) ++l;
        if (l != i && j == k && k == l) return true;
    }
    return false;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (i > 0) sum[i] = sum[i - 1] + A[i];
        else sum[i] = A[i];
    }
    for (int i = N; i < 2*N; i++) sum[i] = sum[i - N] + A[i - N];
    
    int64 low = 0, high = INF;
    while (high != low) {
        int64 mid = (low + high + 1) >> 1;
        if (calc(mid)) low = mid;
        else high = mid - 1;
    }
    printf("%lld\n", low);
}
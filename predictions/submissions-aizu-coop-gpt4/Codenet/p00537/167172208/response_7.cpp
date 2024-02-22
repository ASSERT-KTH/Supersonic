#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int seg[MAXN << 2] = {0}, add[MAXN << 2] = {0}, P[MAXN], u[MAXN], v[MAXN];
void Add(int a, int b, int x, int k, int l, int r) {
    if (a >= r || b <= l) {
        return;
    } else if (a <= l && r <= b) {
        add[k] += x;
    } else {
        Add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        Add(a, b, x, 2 * k + 2, (l + r) / 2, r);
        seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
    }
}
int Query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l)
        return (0);
    if (a <= l && r <= b)
        return (seg[k] + add[k]);
    return (Query(a, b, 2 * k + 1, l, (l + r) / 2) +
            Query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k]);
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &P[i]);
        --P[i];
    }
    for (int i = 1; i < M; i++) {
        u[i] = min(P[i - 1], P[i]), v[i] = max(P[i - 1], P[i]);
        Add(u[i], v[i], 1, 0, 0, N);
    }
    long long ret = 0;
    for (int i = 0; i < N - 1; i++) {
        long long used = Query(i, i + 1, 0, 0, N);
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        ret += min(used * A, C + used * B);
    }
    printf("%lld\n", ret);
    return 0;
}
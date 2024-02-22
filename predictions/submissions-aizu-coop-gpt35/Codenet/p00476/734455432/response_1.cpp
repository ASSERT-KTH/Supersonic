#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;
int N, H;
int* d;
int* h;
const int size = 1 << 20;
int* seg_v;
int* seg_a;
Pr* rmq;

void seg_init() {
    seg_v = new int[size * 2 - 1]();
    seg_a = new int[size * 2 - 1]();
}

void seg_add(int l, int r, int x) {
    // TODO: Implement seg_add function
}

int seg_getMax(int l, int r) {
    // TODO: Implement seg_getMax function
}

void rmq_init() {
    rmq = new Pr[size * 2 - 1];
}

void rmq_update(int k, int x) {
    // TODO: Implement rmq_update function
}

Pr rmq_getMax(int l, int r) {
    // TODO: Implement rmq_getMax function
}

void solve() {
    long long int res = 0;

    for (int i = 0; i < N; i++) {
        rmq_update(i, h[i]);
    }

    seg_init();
    seg_add(0, N, H);

    int seg_max = seg_getMax(0, 1);

    for (int fl = 0; fl < N; fl++) {
        if (seg_max > H) {
            seg_add(fl, N, H - seg_max);
        }

        seg_add(fl, N, -d[fl]);

        seg_max = seg_getMax(fl, fl + 1);

        if (seg_max > 0)
            continue;

        while (true) {
            int idx = rmq_getMax(0, fl).second;

            if (h[idx] > H - seg_max) {
                h[idx] = H - seg_max;
                rmq_update(idx, h[idx]);
                continue;
            }

            int s = (H - seg_max) / h[idx];
            int hp = seg_max;
            int need = -hp + 1;
            int t = (need / h[idx]) + !!(need % h[idx]);
            int num = min(s, t);
            seg_add(idx, N, h[idx] * num);
            res += num;
            seg_max = seg_getMax(fl, fl + 1);

            if (seg_max > 0)
                break;
        }
    }

    printf("%lld\n", res);
}

int main() {
    scanf("%d %d", &N, &H);

    d = new int[N];
    h = new int[N];

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", d + i + 1, h + i);
    }

    rmq_init();
    solve();

    delete[] d;
    delete[] h;
    delete[] seg_v;
    delete[] seg_a;
    delete[] rmq;

    return 0;
}
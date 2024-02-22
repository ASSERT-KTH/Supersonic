#include <iostream>
#include <vector>

struct Pair {
    int first, second;

    Pair(int f = 0, int s = 0) : first(f), second(s) {}
};

const int INF = 1 << 28;

int N, H;
std::vector<int> d, h;
int segmentTreeSize;
std::vector<int> seg_v, seg_a;
std::vector<Pair> rmq;

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = segmentTreeSize) {
    if (b <= l || r <= a)
        return;
    if (l <= a && b <= r) {
        seg_a[k] += x;
        while (k) {
            k = (k - 1) / 2;
            seg_v[k] = std::max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1], seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
        }
        return;
    }
    int m = (a + b) / 2;
    seg_add(l, r, x, k * 2 + 1, a, m);
    seg_add(l, r, x, k * 2 + 2, m, b);
}

int seg_getMax(int l, int r, int k = 0, int a = 0, int b = segmentTreeSize) {
    if (b <= l || r <= a)
        return -INF;
    if (l <= a && b <= r)
        return seg_a[k] + seg_v[k];
    int m = (a + b) / 2;
    int vl = seg_getMax(l, r, k * 2 + 1, a, m);
    int vr = seg_getMax(l, r, k * 2 + 2, m, b);
    return seg_a[k] + std::max(vl, vr);
}

void rmq_update(int k, int x) {
    int i = k;
    k += segmentTreeSize - 1;
    rmq[k] = Pair(x, i);
    while (k) {
        k = (k - 1) / 2;
        rmq[k] = std::max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
    }
}

Pair _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = segmentTreeSize) {
    if (b <= l || r <= a)
        return Pair(-INF, -1);
    if (l <= a && b <= r)
        return rmq[k];
    int m = (a + b) / 2;
    Pair vl = _rmq_getMax(l, r, k * 2 + 1, a, m);
    Pair vr = _rmq_getMax(l, r, k * 2 + 2, m, b);
    return std::max(vl, vr);
}

int rmq_getMax(int l, int r) {
    return _rmq_getMax(l, r).first;
}

int rmq_getMaxIdx(int l, int r) {
    return _rmq_getMax(l, r).second;
}

void solve() {
    long long int res = 0;

    for (int i = 0; i < N; ++i) {
        rmq_update(i, h[i]);
    }

    seg_add(0, N, H);

    for (int fl = 0; fl < N; ++fl) {
        int maxFl = seg_getMax(fl, fl + 1);

        if (maxFl > H) {
            seg_add(fl, N, H - maxFl);
        }

        seg_add(fl, N, -d[fl]);

        if (seg_getMax(fl, fl + 1) > 0) {
            continue;
        }

        while (true) {
            int idx = rmq_getMaxIdx(0, fl);

            if (h[idx] > H - seg_getMax(idx, fl)) {
                h[idx] = H - seg_getMax(idx, fl);
                rmq_update(idx, h[idx]);
                continue;
            }

            int s = (H - seg_getMax(idx, fl)) / h[idx];
            int hp = seg_getMax(fl, fl + 1);
            int need = -hp + 1;
            int t = (need / h[idx]) + !!(need % h[idx]);
            int num = std::min(s, t);

            seg_add(idx, N, h[idx] * num);
            res += num;

            if (seg_getMax(fl, fl + 1) > 0) {
                break;
            }
        }
    }

    std::cout << res << "\n";
}

int main() {
    std::cin >> N >> H;

    d.resize(N - 1);
    h.resize(N - 1);

    for (int i = 0; i < N - 1; ++i) {
        std::cin >> d[i] >> h[i];
    }

    segmentTreeSize = 1;
    while (segmentTreeSize < N) {
        segmentTreeSize <<= 1;
    }

    seg_v.resize(segmentTreeSize * 2 - 1);
    seg_a.resize(segmentTreeSize * 2 - 1);
    rmq.resize(segmentTreeSize * 2 - 1);

    solve();

    return 0;
}
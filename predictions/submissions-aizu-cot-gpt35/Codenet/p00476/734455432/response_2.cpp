#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;

struct SegmentTree {
    int size;
    vector<int> seg;
    vector<int> seg_a;

    SegmentTree(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }

        seg.resize(size * 2 - 1, -INF);
        seg_a.resize(size * 2 - 1, 0);
    }

    void add(int l, int r, int x, int k = 0, int a = 0, int b = size) {
        if (b <= l || r <= a)
            return;
        if (l <= a && b <= r) {
            seg_a[k] += x;
            seg[k] += x;
            return;
        }
        int m = (a + b) / 2;
        add(l, r, x, k * 2 + 1, a, m);
        add(l, r, x, k * 2 + 2, m, b);
        seg[k] = max(seg[k * 2 + 1] + seg_a[k * 2 + 1], seg[k * 2 + 2] + seg_a[k * 2 + 2]);
    }

    int getMax(int l, int r, int k = 0, int a = 0, int b = size) {
        if (b <= l || r <= a)
            return -INF;
        if (l <= a && b <= r)
            return seg[k] + seg_a[k];
        int m = (a + b) / 2;
        int vl = getMax(l, r, k * 2 + 1, a, m);
        int vr = getMax(l, r, k * 2 + 2, m, b);
        return seg_a[k] + max(vl, vr);
    }
};

void solve() {
    int N, H;
    scanf("%d %d", &N, &H);
    vector<int> d(N), h(N);

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &d[i + 1], &h[i]);
    }

    SegmentTree seg(N);
    priority_queue<Pr> pq;

    long long int res = 0;

    for (int i = 0; i < N; i++) {
        pq.push(Pr(h[i], i));
    }

    seg.add(0, N, H);

    for (int fl = 0; fl < N; fl++) {
        int maxVal = seg.getMax(fl, fl + 1);

        if (maxVal > H) {
            seg.add(fl, N, H - maxVal);
        }

        seg.add(fl, N, -d[fl]);

        if (seg.getMax(fl, fl + 1) > 0)
            continue;

        while (true) {
            int idx = pq.top().second;
            pq.pop();

            if (h[idx] > H - seg.getMax(idx, fl)) {
                h[idx] = H - seg.getMax(idx, fl);
                seg.add(idx, N, h[idx]);
                pq.push(Pr(h[idx], idx));
                continue;
            }

            int s = (H - seg.getMax(idx, fl)) / h[idx];
            int hp = seg.getMax(fl, fl + 1);
            int need = -hp + 1;
            int t = (need / h[idx]) + !!(need % h[idx]);
            int num = min(s, t);
            seg.add(idx, N, h[idx] * num);
            res += num;
            if (seg.getMax(fl, fl + 1) > 0)
                break;
        }
    }

    printf("%lld\n", res);
}

int main() {
    solve();
    return 0;
}
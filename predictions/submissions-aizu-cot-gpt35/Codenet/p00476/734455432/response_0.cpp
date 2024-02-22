#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;

int N, H;
vector<int> d, h;
vector<int> seg_v, seg_a;
vector<pair<int, int>> rmq;

void seg_add(int l, int r, int x) {
    int k = 0, a = 0, b = N;

    while (b > l && r > a) {
        if (l <= a && b <= r) {
            seg_a[k] += x;
            while (k) {
                k = (k - 1) / 2;
                seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1],
                               seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
            }
            return;
        }
        int m = (a + b) / 2;
        seg_add(l, r, x, k * 2 + 1, a, m);
        seg_add(l, r, x, k * 2 + 2, m, b);
    }
}

int seg_getMax(int l, int r) {
    int k = 0, a = 0, b = N;

    int res = -INF;
    while (b > l && r > a) {
        if (l <= a && b <= r) {
            return seg_a[k] + seg_v[k];
        }
        int m = (a + b) / 2;
        int vl = seg_getMax(l, r, k * 2 + 1, a, m);
        int vr = seg_getMax(l, r, k * 2 + 2, m, b);
        res = max(res, seg_a[k] + max(vl, vr));
        return res;
    }
    return res;
}

void rmq_update(int k, int x) {
    int i = k;
    k += N - 1;
    rmq[k] = make_pair(x, i);
    while (k) {
        k = (k - 1) / 2;
        rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
    }
}

pair<int, int> rmq_getMax(int l, int r) {
    int k = 0, a = 0, b = N;

    pair<int, int> res(-INF, -1);
    while (b > l && r > a) {
        if (l <= a && b <= r) {
            return rmq[k];
        }
        int m = (a + b) / 2;
        pair<int, int> vl = rmq_getMax(l, r, k * 2 + 1, a, m);
        pair<int, int> vr = rmq_getMax(l, r, k * 2 + 2, m, b);
        res = max(res, max(vl, vr));
        return res;
    }
    return res;
}

void solve() {
    long long int res = 0;

    for (int i = 0; i < N; i++) {
        rmq_update(i, h[i]);
    }

    seg_add(0, N, H);

    for (int fl = 0; fl < N; fl++) {
        int max_fl = seg_getMax(fl, fl + 1);
        if (max_fl > H) {
            seg_add(fl, N, H - max_fl);
        }
        seg_add(fl, N, -d[fl]);
        int max_fl_after_update = seg_getMax(fl, fl + 1);
        if (max_fl_after_update > 0) {
            continue;
        }
        while (true) {
            pair<int, int> max_idx = rmq_getMaxIdx(0, fl);
            int idx = max_idx.second;
            int max_idx_fl = max_idx.first;

            if (h[idx] > H - max_idx_fl) {
                h[idx] = H - max_idx_fl;
                rmq_update(idx, h[idx]);
                continue;
            }
            int s = (H - max_idx_fl) / h[idx];
            int hp = seg_getMax(fl, fl + 1);
            int need = -hp + 1;
            int t = (need / h[idx]) + !!(need % h[idx]);
            int num = min(s, t);
            seg_add(idx, N, h[idx] * num);
            res += num;
            if (seg_getMax(fl, fl + 1) > 0) {
                break;
            }
        }
    }

    cout << res << endl;
}

int main() {
    cin >> N >> H;

    d.resize(N - 1);
    h.resize(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> d[i] >> h[i];
    }

    seg_v.resize(N * 2 - 1);
    seg_a.resize(N * 2 - 1);
    rmq.resize(N * 2 - 1);

    solve();

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegTree {
    int n;
    vector<int> Max;
    vector<int> Min;

    void init(int n_) {
        n = 1;
        while (n < n_) {
            n *= 2;
        }
        Max.assign(2 * n, -inf);
        Min.assign(2 * n, inf);
    }

    void update(int idx, int val) {
        idx += n - 1;
        Min[idx] = val;
        Max[idx] = val;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            Min[idx] = min(Min[idx * 2 + 1], Min[idx * 2 + 2]);
            Max[idx] = max(Max[idx * 2 + 1], Max[idx * 2 + 2]);
        }
    }

    pair<int, int> query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) {
            r = n;
        }
        if (r <= a || b <= l) {
            return make_pair(inf, -inf);
        }
        if (a <= l && r <= b) {
            return make_pair(Min[k], Max[k]);
        }
        pair<int, int> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        pair<int, int> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return make_pair(min(vl.first, vr.first), max(vl.second, vr.second));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, d;
    cin >> N >> d;

    SegTree x_seg, y_seg;
    x_seg.init(N);
    y_seg.init(N);

    vector<pair<int, int>> hoge;
    hoge.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x, y, b;
        cin >> x >> y >> b;
        hoge.emplace_back(b, i);
    }

    partial_sort(hoge.begin(), hoge.begin() + N, hoge.end());

    for (int i = 0; i < N; ++i) {
        x_seg.update(i, x[hoge[i].second]);
        y_seg.update(i, y[hoge[i].second]);
    }

    ll ans = -inf;

    for (int i = 0; i < N; ++i) {
        int b = hoge[i].first;
        int idx = upper_bound(hoge.begin(), hoge.end(), make_pair(b + d, inf)) - hoge.begin();
        pair<int, int> x_range = x_seg.query(i, idx);
        pair<int, int> y_range = y_seg.query(i, idx);
        ans = max(ans, 1ll * (x_range.second - x_range.first) * (y_range.second - y_range.first));
    }

    cout << ans << '\n';

    return 0;
}
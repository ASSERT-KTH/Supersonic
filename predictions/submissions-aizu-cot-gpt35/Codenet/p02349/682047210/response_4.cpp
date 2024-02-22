#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

template <typename Monoid>
struct LazySegmentTree {
    const int N;
    vector<Monoid> node, lazy;

    LazySegmentTree(int sz = 0) : N(1) {
        while (N < sz) {
            N <<= 1;
        }
        node.resize(2 * N - 1, 0);
        lazy.resize(2 * N - 1, 0);
    }

    void build(const vector<Monoid> &v) {
        int sz = int(v.size());
        for (int i = 0; i < sz; i++) {
            node[i + N - 1] = v[i];
        }
        for (int i = N - 2; i >= 0; i--) {
            node[i] = node[i * 2 + 1] + node[i * 2 + 2];
        }
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k] * (r - l);
            if (k < N - 1) {
                lazy[2 * k + 1] += lazy[k];
                lazy[2 * k + 2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, Monoid x) {
        int k = 0, l = 0, r = N;
        while (true) {
            eval(k, l, r);
            if (b <= l || r <= a) {
                return;
            }
            if (a <= l && r <= b) {
                lazy[k] += x;
                eval(k, l, r);
                return;
            }
            int m = (l + r) / 2;
            if (a < m) {
                add(a, b, x, 2 * k + 1, l, m);
            }
            if (m < b) {
                add(a, b, x, 2 * k + 2, m, r);
            }
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    Monoid getSum(int a, int b) {
        int k = 0, l = 0, r = N;
        Monoid res = 0;
        while (true) {
            eval(k, l, r);
            if (b <= l || r <= a) {
                return res;
            }
            if (a <= l && r <= b) {
                return res + node[k];
            }
            int m = (l + r) / 2;
            if (a < m) {
                res += getSum(a, b, 2 * k + 1, l, m);
            }
            if (m < b) {
                res += getSum(a, b, 2 * k + 2, m, r);
            }
            return res;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    LazySegmentTree<ll> seg(n);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            ll s, t, x;
            cin >> s >> t >> x;
            seg.add(s - 1, t, x);
        } else {
            int s;
            cin >> s;
            cout << seg.getSum(s - 1, s) << endl;
        }
    }
    return 0;
}
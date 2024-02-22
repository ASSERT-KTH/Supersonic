#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <typename Monoid>
struct LazySegmentTree {
    int N;
    vector<Monoid> node, lazy;

    LazySegmentTree(int sz = 0) {
        N = 1;
        while (N < sz) N <<= 1;
        node.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
    }

    // ... rest of the code remains the same ...
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<ll> seg(n);
    for (int i = 0; i < q; ++i) {
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
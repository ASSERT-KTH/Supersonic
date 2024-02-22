#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100000

using namespace std;

struct seg_tree{
    int N, H;
    vector<int> d, h, seg_v, seg_a, rmq, rmq_index;
    int seg_size;

    seg_tree(int n, int h): N(n), H(h), d(n), h(n), seg_v(2*n-1), seg_a(2*n-1), rmq(2*n-1), rmq_index(2*n-1), seg_size(n) {}

    void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = SIZE) {
        if (b <= l || r <= a) return;
        if (l <= a && b <= r) {
            seg_a[k] += x;
            while (k) {
                k = (k - 1) / 2;
                seg_v[k] = max(seg_v[k * 2 + 1] + seg_a[k * 2 + 1], seg_v[k * 2 + 2] + seg_a[k * 2 + 2]);
            }
            return;
        }
        int m = (a + b) / 2;
        seg_add(l, r, x, k * 2 + 1, a, m);
        seg_add(l, r, x, k * 2 + 2, m, b);
    }

    // ... rest of the functions go here ...
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;
    seg_tree st(N, H);
    for (int i = 0; i < N - 1; i++) {
        cin >> st.d[i + 1] >> st.h[i];
    }
    st.solve();
}
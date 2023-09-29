#include <cstdio>
#include <vector>

struct SegmentTree {
    std::vector<int> seg, add;
    int sz;
    SegmentTree(int n) : sz(1) {
        while (sz < n) {sz *= 2;}
        seg.assign(sz * 2 + 1, 0);
        add.assign(sz * 2 + 1, 0);
    }
    void add(int a, int b, int x, int k, int l, int r) {
        if (a >= r || b <= l) {return;}
        if (a <= l && r <= b) {
            add[k] += x;
        } else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            seg[k] = seg[2 * k + 1] + add[2 * k + 1] + seg[2 * k + 2] + add[2 * k + 2];
        }
    }
    int query(int a, int b, int k, int l, int r) {
        if (a >= r || b <= l) {return (0);}
        if (a <= l && r <= b) {return (seg[k] + add[k]);}
        return (query(a, b, 2 * k + 1, l, (l + r) / 2) + query(a, b, 2 * k + 2, (l + r) / 2, r) + add[k]);
    }
    void add(int a, int b, int x) {add(a, b, x, 0, 0, sz);}
    int query(int a, int b) {return query(a, b, 0, 0, sz);}
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    SegmentTree segtree(n);
    std::vector<int> p(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
        --p[i];
    }
    for (int i = 1; i < m; i++) {
        int u = std::min(p[i - 1], p[i]), v = std::max(p[i - 1], p[i]);
        segtree.add(u, v, 1);
    }

    long long ret = 0;
    for (int i = 0; i < n - 1; i++) {
        long long used = segtree.query(i, i + 1);
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ret += std::min(used * a, c + used * b);
    }
    printf("%lld\n", ret);
    return 0;
}
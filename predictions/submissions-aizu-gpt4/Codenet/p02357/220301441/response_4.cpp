#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#define rep(i, a, b) for (uint32 i = (a); i < (b); ++i)
using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

struct RMQ {
    int n;
    std::vector<int> data;
    RMQ(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2 * n - 1, INT32_MAX);
    }
    void update(int i, int x) {
        i += n - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = std::min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INT32_MAX;
        if (a <= l && r <= b) return data[k];
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return std::min(vl, vr);
    }
    int query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    uint32 n, l;
    std::cin >> n >> l;
    std::vector<uint32> a(n);
    rep(i, 0, n) { std::cin >> a[i]; }
    RMQ rmq(n);
    rep(i, 0, n) { rmq.update(i, a[i]); }
    std::cout << rmq.query(0, l);
    rep(i, 1, n - l + 1) { std::cout << " " << rmq.query(i, i + l); }
    std::cout << "\n";
    return 0;
}
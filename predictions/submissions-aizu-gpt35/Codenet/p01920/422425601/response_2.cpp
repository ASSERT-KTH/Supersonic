#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cerr << #x << " = " << x << endl
#else
#define print(x)
#endif
using i64 = long long;
struct sqrt_decomp {
    const int bucket_size = 256;
    int length, bucket_num;
    vector<vector<int>> buckets;
    vector<int> update, bucket_sum;

    sqrt_decomp(const vector<int> &x) : length(x.size()), bucket_num((x.size() + bucket_size - 1) / bucket_size) {
        buckets.resize(bucket_num);
        update.resize(bucket_num);
        bucket_sum.resize(bucket_num);
        for (int i = 0; i < x.size(); ++i) {
            buckets[i / bucket_size].push_back(x[i]);
            bucket_sum[i / bucket_size] += x[i];
            update[i / bucket_size] = 2;
        }
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < bucket_num; ++i) {
            if (update[i] == 2)
                res += bucket_sum[i];
            else
                res += update[i] * buckets[i].size();
        }
        return res;
    }

    void query(int l, int r, int b) {
        l = max(0, l);
        r = min(length - 1, r);
        int l_buk = l / bucket_size, r_buk = r / bucket_size;
        if (l_buk == r_buk) {
            if (update[l_buk] < 2) {
                for (auto &a : buckets[l_buk]) a = update[l_buk];
                bucket_sum[l_buk] = update[l_buk] * buckets[l_buk].size();
                update[l_buk] = 2;
            }
            rep(i, l, r + 1) bucket_sum[l_buk] += b - buckets[l_buk][i % bucket_size], buckets[l_buk][i % bucket_size] = b;
            return;
        }
        if (update[l_buk] < 2) {
            for (auto &a : buckets[l_buk]) a = update[l_buk];
            bucket_sum[l_buk] = update[l_buk] * buckets[l_buk].size();
            update[l_buk] = 2;
        }
        rep(i, l, (l_buk + 1) * bucket_size) bucket_sum[l_buk] += b - buckets[l_buk][i % bucket_size], buckets[l_buk][i % bucket_size] = b;
        if (update[r_buk] < 2) {
            for (auto &a : buckets[r_buk]) a = update[r_buk];
            bucket_sum[r_buk] = update[r_buk] * buckets[r_buk].size();
            update[r_buk] = 2;
        }
        rep(i, r_buk * bucket_size, r + 1) bucket_sum[r_buk] += b - buckets[r_buk][i % bucket_size], buckets[r_buk][i % bucket_size] = b;
        rep(i, l_buk + 1, r_buk) update[i] = b;
    }

    int at(int i) {
        int bucket_index = i / bucket_size;
        if (update[bucket_index] < 2)
            return update[bucket_index];
        else
            return buckets[bucket_index][i % bucket_size];
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> x1, x2;
    rep(i, 0, n) {
        x1.push_back(s[i] - '0');
        if (i + 1 < n) x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
    }
    sqrt_decomp f(x1), g(x2);
    rep(i, 0, q) {
        int l, r, b;
        cin >> l >> r >> b;
        --l, --r;
        f.query(l, r, b);
        if (b == 0) g.query(l - 1, r, 0);
        else {
            int l_ = l, r_ = r - 1;
            if (0 <= l - 1 and f.at(l - 1)) --l_;
            if (r + 1 < n and f.at(r + 1)) ++r_;
            g.query(l_, r_, 1);
        }
        cout << f.sum() - g.sum() << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
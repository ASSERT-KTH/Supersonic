#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int bucket_size = 256;

class sqrt_decomp {
    vector<int> update, bucket_sum;
    vector<vector<int>> buckets;
    int length, bucket_num;

public:

    sqrt_decomp(const vector<int>& x)
        : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        update(bucket_num, 2),
        bucket_sum(bucket_num, 0),
        buckets(bucket_num) {
        for (int i = 0; i < x.size(); ++i) {
            buckets[i / bucket_size].push_back(x[i]);
            bucket_sum[i / bucket_size] += x[i];
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
        int bl = l / bucket_size;
        int br = r / bucket_size;
        if (bl == br) {
            for (int i = l; i <= r; ++i) {
                bucket_sum[bl] -= buckets[bl][i % bucket_size];
                buckets[bl][i % bucket_size] = b;
                bucket_sum[bl] += b;
            }
        }
        else {
            for (int i = l, end = (bl + 1) * bucket_size; i < end; ++i) {
                bucket_sum[bl] -= buckets[bl][i % bucket_size];
                buckets[bl][i % bucket_size] = b;
                bucket_sum[bl] += b;
            }
            for (int i = bl + 1; i < br; ++i) {
                bucket_sum[i] = b * buckets[i].size();
                update[i] = b;
            }
            for (int i = br * bucket_size; i <= r; ++i) {
                bucket_sum[br] -= buckets[br][i % bucket_size];
                buckets[br][i % bucket_size] = b;
                bucket_sum[br] += b;
            }
        }
    }

    int at(int i) {
        int bucket_index = i / bucket_size;
        if (update[bucket_index] < 2)
            return update[bucket_index];
        else
            return buckets[bucket_index][i % bucket_size];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> x1, x2;
    for (int i = 0; i < n; i++) {
        x1.push_back(s[i] - '0');
        if (i + 1 < n)
            x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
    }
    sqrt_decomp f(x1), g(x2);
    for (int i = 0; i < q; i++) {
        int l, r, b;
        cin >> l >> r >> b;
        l--; r--;
        f.query(l, r, b);
        if (b == 0)
            g.query(l - 1, r, 0);
        else {
            int l_ = l, r_ = r - 1;
            if (l > 0 and f.at(l - 1))
                --l_;
            if (r + 1 < n and f.at(r + 1))
                ++r_;
            g.query(l_, r_, 1);
        }
        cout << f.sum() - g.sum() << '\n';
    }
    return 0;
}
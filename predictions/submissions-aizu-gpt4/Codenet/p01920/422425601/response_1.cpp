#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

struct sqrt_decomp {
    const int bucket_size = 256;
    int length, bucket_num;
    vector<vector<int>> buckets;
    vector<int> update, bucket_sum;

    sqrt_decomp(const vector<int> &x)
        : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        buckets(bucket_num),
        update(bucket_num, 2),
        bucket_sum(bucket_num) {
        for (int i = 0; i < length; ++i) {
            buckets[i / bucket_size].push_back(x[i]);
            bucket_sum[i / bucket_size] += x[i];
        }
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < bucket_num; ++i) {
            res += (update[i] == 2 ? bucket_sum[i] : update[i] * buckets[i].size());
        }
        return res;
    }

    void query(int l, int r, int b) {
        l = max(0, l);
        r = min(length - 1, r);
        while (l % bucket_size != 0 && l <= r) {
            int bucket_index = l / bucket_size;
            if (update[bucket_index] < 2) {
                fill(buckets[bucket_index].begin(), buckets[bucket_index].end(), update[bucket_index]);
                bucket_sum[bucket_index] = update[bucket_index] * buckets[bucket_index].size();
                update[bucket_index] = 2;
            }
            bucket_sum[bucket_index] -= buckets[bucket_index][l % bucket_size];
            buckets[bucket_index][l % bucket_size] = b;
            bucket_sum[bucket_index] += b;
            ++l;
        }
        while ((r + 1) % bucket_size != 0 && l <= r) {
            int bucket_index = r / bucket_size;
            if (update[bucket_index] < 2) {
                fill(buckets[bucket_index].begin(), buckets[bucket_index].end(), update[bucket_index]);
                bucket_sum[bucket_index] = update[bucket_index] * buckets[bucket_index].size();
                update[bucket_index] = 2;
            }
            bucket_sum[bucket_index] -= buckets[bucket_index][r % bucket_size];
            buckets[bucket_index][r % bucket_size] = b;
            bucket_sum[bucket_index] += b;
            --r;
        }
        fill(update.begin() + l/bucket_size, update.begin() + r/bucket_size + 1, b);
    }

    int at(int i) {
        int bucket_index = i / bucket_size;
        return update[bucket_index] < 2 ? update[bucket_index] : buckets[bucket_index][i % bucket_size];
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> x1(n), x2(n-1);
    for (int i = 0; i < n; ++i) {
        x1[i] = s[i] - '0';
        if (i + 1 < n)
            x2[i] = (s[i] - '0') * (s[i + 1] - '0');
    }
    sqrt_decomp f(x1), g(x2);
    for (int i = 0; i < q; i++) {
        int l, r, b;
        cin >> l >> r >> b;
        --l; --r;
        f.query(l, r, b);
        if (b == 0)
            g.query(l - 1, r, 0);
        else {
            if (l > 0 && f.at(l - 1)) --l;
            if (r < n-1 && f.at(r + 1)) ++r;
            g.query(l, r - 1, 1);
        }
        cout << f.sum() - g.sum() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
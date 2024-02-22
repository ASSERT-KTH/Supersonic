#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sqrt_decomp {
    const int bucket_size = 256;
    int length, bucket_num;
    vector<int> buckets;
    vector<int> update, bucket_sum;

    sqrt_decomp(const string& s)
        : length(s.size()),
        bucket_num((s.size() + bucket_size - 1) / bucket_size) {
        buckets.resize(bucket_num * bucket_size);
        update.resize(bucket_num);
        bucket_sum.resize(bucket_num);

        for (int i = 0; i < s.size(); ++i) {
            int bucket_index = i / bucket_size;
            buckets[bucket_index * bucket_size + i % bucket_size] = s[i] - '0';
            bucket_sum[bucket_index] += s[i] - '0';
            update[bucket_index] = 2;
        }
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < bucket_num; ++i) {
            if (update[i] == 2)
                res += bucket_sum[i];
            else
                res += update[i] * bucket_size;
        }
        return res;
    }

    void query(int l, int r, int b) {
        l = max(0, l);
        r = min(length - 1, r);

        int l_bucket_index = l / bucket_size;
        int r_bucket_index = r / bucket_size;

        for (int i = l_bucket_index + 1; i < r_bucket_index; ++i) {
            update[i] = b;
            bucket_sum[i] = b * bucket_size;
        }

        if (l_bucket_index == r_bucket_index) {
            for (int i = l; i <= r; ++i) {
                int bucket_index = l / bucket_size;
                bucket_sum[bucket_index] -= buckets[bucket_index * bucket_size + i % bucket_size];
                buckets[bucket_index * bucket_size + i % bucket_size] = b;
                bucket_sum[bucket_index] += b;
            }
        } else {
            for (int i = l; i < (l_bucket_index + 1) * bucket_size; ++i) {
                int bucket_index = l / bucket_size;
                bucket_sum[bucket_index] -= buckets[bucket_index * bucket_size + i % bucket_size];
                buckets[bucket_index * bucket_size + i % bucket_size] = b;
                bucket_sum[bucket_index] += b;
            }
            for (int i = r_bucket_index * bucket_size; i <= r; ++i) {
                int bucket_index = r / bucket_size;
                bucket_sum[bucket_index] -= buckets[bucket_index * bucket_size + i % bucket_size];
                buckets[bucket_index * bucket_size + i % bucket_size] = b;
                bucket_sum[bucket_index] += b;
            }
        }
    }

    int at(int i) {
        int bucket_index = i / bucket_size;
        if (update[bucket_index] < 2)
            return update[bucket_index];
        else
            return buckets[bucket_index * bucket_size + i % bucket_size];
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;

    sqrt_decomp f(s);

    int f_sum = f.sum();
    int g_sum = 0;

    for (int i = 0; i < q; i++) {
        int l, r, b;
        cin >> l >> r >> b;
        l--;
        r--;

        f.query(l, r, b);

        if (b == 0)
            g_sum += f.at(l - 1) * f.at(l);
        else
            g_sum += f.at(l - 1) * b + f.at(r + 1) * b - f.at(l - 1) * f.at(r + 1);

        cout << f_sum - g_sum << endl;
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
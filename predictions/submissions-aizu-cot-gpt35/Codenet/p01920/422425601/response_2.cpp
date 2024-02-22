#include <iostream>
#include <vector>
#include <array>

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (const auto& v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

using i64 = int64_t;

struct sqrt_decomp {
    const int bucket_size = 256;
    int length, bucket_num;
    std::vector<std::array<int, 256>> buckets;
    std::vector<int> update, bucket_sum;

    sqrt_decomp(const std::vector<int>& x)
        : length(x.size()),
          bucket_num((x.size() + bucket_size - 1) / bucket_size),
          buckets(bucket_num),
          update(bucket_num, 2),
          bucket_sum(bucket_num)
    {
        for (int i = 0; i < x.size(); ++i) {
            buckets[i / bucket_size][i % bucket_size] = x[i];
            bucket_sum[i / bucket_size] += x[i];
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
        l = std::max(0, l);
        r = std::min(length - 1, r);
        int l_bucket = l / bucket_size;
        int r_bucket = r / bucket_size;

        if (l_bucket == r_bucket) {
            for (int i = l; i <= r; ++i) {
                if (update[l_bucket] < 2) {
                    bucket_sum[l_bucket] -= buckets[l_bucket][i % bucket_size];
                    buckets[l_bucket][i % bucket_size] = b;
                    bucket_sum[l_bucket] += b;
                }
                update[l_bucket] = b;
            }
        } else {
            for (int i = l; i < (l_bucket + 1) * bucket_size; ++i) {
                if (update[l_bucket] < 2) {
                    bucket_sum[l_bucket] -= buckets[l_bucket][i % bucket_size];
                    buckets[l_bucket][i % bucket_size] = b;
                    bucket_sum[l_bucket] += b;
                }
                update[l_bucket] = b;
            }

            for (int i = l_bucket + 1; i < r_bucket; ++i) {
                update[i] = b;
                bucket_sum[i] = b * bucket_size;
            }

            for (int i = r_bucket * bucket_size; i <= r; ++i) {
                if (update[r_bucket] < 2) {
                    bucket_sum[r_bucket] -= buckets[r_bucket][i % bucket_size];
                    buckets[r_bucket][i % bucket_size] = b;
                    bucket_sum[r_bucket] += b;
                }
                update[r_bucket] = b;
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

void solve() {
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;
    std::vector<int> x1, x2;
    for (int i = 0; i < n; i++) {
        x1.push_back(s[i] - '0');
        if (i + 1 < n)
            x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
    }
    sqrt_decomp f(x1), g(x2);
    for (int i = 0; i < q; i++) {
        int l, r, b;
        std::cin >> l >> r >> b;
        l--;
        r--;
        f.query(l, r, b);
        if (b == 0)
            g.query(l - 1, r, 0);
        else {
            int l_ = l, r_ = r - 1;
            if (0 <= l - 1 && f.at(l - 1))
                --l_;
            if (r + 1 < n && f.at(r + 1))
                ++r_;
            g.query(l_, r_, 1);
        }
        std::cout << f.sum() - g.sum() << std::endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

struct sqrt_decomp {
    const int bucket_size = 256;
    int length, bucket_num;
    vector<int> data, update, buckets;

    sqrt_decomp(const vector<int> &x) : length(x.size()), bucket_num((x.size() + bucket_size - 1) / bucket_size) {
        data.assign(length, 0);
        update.assign(bucket_num, 2);
        buckets.assign(bucket_num, 0);

        for (int i = 0; i < length; ++i) {
            data[i] = x[i];
            buckets[i / bucket_size] += x[i];
        }
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < bucket_num; ++i) {
            if (update[i] == 2)
                res += buckets[i];
            else
                res += update[i] * bucket_size;
        }
        return res;
    }

    void apply(int i, int val) {
        buckets[i/bucket_size] -= data[i];
        data[i] = val;
        buckets[i/bucket_size] += data[i];
    }

    void push(int i) {
        if (update[i] < 2) {
            for (int j = i*bucket_size; j < (i+1)*bucket_size; ++j)
                apply(j, update[i]);
            update[i] = 2;
        }
    }

    void query(int l, int r, int b) {
        int l_bucket = l / bucket_size;
        int r_bucket = r / bucket_size;

        if (l_bucket == r_bucket) {
            for (int i = l; i <= r; ++i)
                apply(i, b);
        } else {
            for (int i = l, end = (l_bucket+1)*bucket_size; i < end; ++i)
                apply(i, b);
            for (int i = l_bucket+1; i < r_bucket; ++i)
                update[i] = b;
            for (int i = r_bucket*bucket_size; i <= r; ++i)
                apply(i, b);
        }
    }

    int at(int i) {
        push(i / bucket_size);
        return data[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> x1(n), x2(n-1);

    for (int i = 0; i < n; ++i) {
        x1[i] = s[i] - '0';
        if (i+1 < n)
            x2[i] = s[i] * s[i+1] - '0' * '0';
    }

    sqrt_decomp f(x1), g(x2);

    while (q--) {
        int l, r, b;
        cin >> l >> r >> b;
        --l; --r;

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

        cout << f.sum() - g.sum() << "\n";
    }

    return 0;
}
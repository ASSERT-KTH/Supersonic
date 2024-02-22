#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}

using i64 = int64_t;

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
        bucket_sum(bucket_num, 0) {
    for (int i = 0; i < x.size(); ++i) {
      buckets[i / bucket_size].emplace_back(x[i]);
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
    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;

    if (start_bucket == end_bucket) {
      if (update[start_bucket] < 2) {
        for (int i = l; i <= r; ++i) {
          buckets[start_bucket][i % bucket_size] = b;
        }
        bucket_sum[start_bucket] = b * (r - l + 1);
      } else {
        bucket_sum[start_bucket] += b - buckets[start_bucket][l % bucket_size];
        for (int i = l; i <= r; ++i) {
          buckets[start_bucket][i % bucket_size] = b;
        }
      }
      return;
    }

    if (update[start_bucket] < 2) {
      for (int i = l; i < (start_bucket + 1) * bucket_size; ++i) {
        buckets[start_bucket][i % bucket_size] = b;
      }
      bucket_sum[start_bucket] = b * (start_bucket + 1) * bucket_size - l;
      update[start_bucket] = 2;
    } else {
      bucket_sum[start_bucket] += b * bucket_size - buckets[start_bucket][l % bucket_size];
      for (int i = l; i < (start_bucket + 1) * bucket_size; ++i) {
        buckets[start_bucket][i % bucket_size] = b;
      }
    }

    for (int i = start_bucket + 1; i < end_bucket; ++i) {
      update[i] = b;
      bucket_sum[i] = b * bucket_size;
    }

    if (update[end_bucket] < 2) {
      for (int i = end_bucket * bucket_size; i <= r; ++i) {
        buckets[end_bucket][i % bucket_size] = b;
      }
      bucket_sum[end_bucket] = b * (r - end_bucket * bucket_size + 1);
      update[end_bucket] = 2;
    } else {
      bucket_sum[end_bucket] += b * (r - end_bucket * bucket_size + 1) - buckets[end_bucket][r % bucket_size];
      for (int i = end_bucket * bucket_size; i <= r; ++i) {
        buckets[end_bucket][i % bucket_size] = b;
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
  string s;
  cin >> n >> s >> q;

  vector<int> x1, x2;
  x1.reserve(n);
  x2.reserve(n-1);

  for (int i = 0; i < n; ++i) {
    x1.emplace_back(s[i] - '0');
    if (i + 1 < n)
      x2.emplace_back((s[i] - '0') * (s[i + 1] - '0'));
  }

  sqrt_decomp f(x1), g(x2);

  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--;
    r--;
    f.query(l, r, b);
    if (b == 0)
      g.query(max(l - 1, 0), r, 0);
    else {
      int l_ = l, r_ = r - 1;
      if (l - 1 >= 0 and f.at(l - 1))
        --l_;
      if (r + 1 < n and f.at(r + 1))
        ++r_;
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
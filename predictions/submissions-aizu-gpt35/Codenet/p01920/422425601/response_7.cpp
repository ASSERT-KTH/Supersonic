#include <bits/stdc++.h>
using namespace std;
#define rep(i, buckets, y) for (int i = (buckets); i < (y); ++i)
#define debug(buckets) #buckets << "=" << (buckets)
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(buckets)                                                         \
  std::cerr << debug(buckets) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(buckets)
#endif
const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
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
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num);
    update.resize(bucket_num);
    bucket_sum.resize(bucket_num);

    int idx = 0;
    for (int i = 0; i < bucket_num; ++i) {
      for (int j = 0; j < bucket_size && idx < x.size(); ++j) {
        buckets[i].push_back(x[idx]);
        bucket_sum[i] += x[idx];
        update[i] = 2;
        idx++;
      }
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

    int bl = l / bucket_size, br = r / bucket_size;
    if (bl == br) {
      for (int i = l; i <= r; i++) {
        buckets[bl][i % bucket_size] = b;
        bucket_sum[bl] += b - buckets[bl][i % bucket_size];
      }
      update[bl] = 1;
    } else {
      for (int i = l, e = (bl + 1) * bucket_size - 1; i <= e; i++) {
        buckets[bl][i % bucket_size] = b;
        bucket_sum[bl] += b - buckets[bl][i % bucket_size];
      }
      update[bl] = 1;

      for (int i = bl + 1; i < br; i++) {
        bucket_sum[i] = b * bucket_size;
        update[i] = b;
      }

      for (int i = br * bucket_size; i <= r; i++) {
        buckets[br][i % bucket_size] = b;
        bucket_sum[br] += b - buckets[br][i % bucket_size];
      }
      update[br] = 1;
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
  rep(i, 0, n) {
    x1.push_back(s[i] - '0');
    if (i + 1 < n)
      x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
  }
  sqrt_decomp f(x1), g(x2);
  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--;
    r--;
    f.query(l, r, b);
    if (b == 0)
      g.query(l - 1, r, 0);
    else {
      int l_ = l, r_ = r - 1;
      if (0 <= l - 1 and f.at(l - 1))
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
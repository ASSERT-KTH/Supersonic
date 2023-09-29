#include <bits/stdc++.h>
using namespace std;
#define rep(i, buckets, y) for (int i = (buckets); i < (y); ++i)
#define debug(buckets) #buckets << "=" << (buckets)
#ifdef DEBUG
#define _GLIBCbucketsbuckets_DEBUG
#define print(buckets)                                                         \
  std::cerr << debug(buckets) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(buckets)
#endif
const int inf = 1e9;
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
    while (l % bucket_size != 0 && l <= r) {
      int bucket_index = l / bucket_size;
      if (update[bucket_index] < 2) {
        for (auto &a : buckets[bucket_index])
          a = update[bucket_index];
        bucket_sum[bucket_index] =
            update[bucket_index] * buckets[bucket_index].size();
        update[bucket_index] = 2;
      }
      bucket_sum[bucket_index] -= buckets[bucket_index][l % bucket_size];
      buckets[bucket_index][l % bucket_size] = b;
      bucket_sum[bucket_index] += b;
      ++l;
    }
    while ((r + 1) % bucket_size != 0 and l <= r) {
      int bucket_index = r / bucket_size;
      if (update[bucket_index] < 2) {
        for (auto &a : buckets[bucket_index])
          a = update[bucket_index];
        bucket_sum[bucket_index] =
            update[bucket_index] * buckets[bucket_index].size();
        update[bucket_index] = 2;
      }
      bucket_sum[bucket_index] -= buckets[bucket_index][r % bucket_size];
      buckets[bucket_index][r % bucket_size] = b;
      bucket_sum[bucket_index] += b;
      --r;
    }
    if (l > r)
      return;
    rep(i, l / bucket_size, r / bucket_size + 1) {
      bucket_sum[i] = b * buckets[i].size();
      update[i] = b;
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
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> x1(n), x2(n - 1);
  rep(i, 0, n) {
    x1[i] = s[i] - '0';
    if (i + 1 < n)
      x2[i] = (s[i] - '0') * (s[i + 1] - '0');
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
    cout << f.sum() - g.sum() << "\n";
  }
}
int main() {
  solve();
  return 0;
}
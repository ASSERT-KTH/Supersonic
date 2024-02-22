#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using i64 = int64_t;

constexpr int bucket_size = 256;
constexpr int no_update = 2;

struct sqrt_decomp {
  int length, bucket_num;
  std::vector<std::vector<int>> buckets;
  std::vector<int> update, bucket_sum;

  sqrt_decomp(const std::vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        buckets(bucket_num),
        update(bucket_num, no_update),
        bucket_sum(bucket_num) {
    for (int i = 0; i < x.size(); ++i) {
      int bucket_index = i / bucket_size;
      buckets[bucket_index].push_back(x[i]);
      bucket_sum[bucket_index] += x[i];
    }
  }

  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      if (update[i] == no_update)
        res += bucket_sum[i];
      else
        res += update[i] * buckets[i].size();
    }
    return res;
  }

  void query(int l, int r, int b) {
    l = std::max(0, l);
    r = std::min(length - 1, r);
    while ((l % bucket_size != 0 || r % bucket_size != bucket_size - 1) && l <= r) {
      int bucket_index = l / bucket_size;
      if (update[bucket_index] != no_update) {
        bucket_sum[bucket_index] = update[bucket_index] * buckets[bucket_index].size();
        std::fill(buckets[bucket_index].begin(), buckets[bucket_index].end(), update[bucket_index]);
        update[bucket_index] = no_update;
      }
      bucket_sum[bucket_index] += b - buckets[bucket_index][l % bucket_size];
      buckets[bucket_index][l % bucket_size] = b;
      l += l % bucket_size != 0 ? 1 : r % bucket_size - bucket_size + 2;
    }
    if (l <= r) {
      int l_bucket = l / bucket_size;
      int r_bucket = r / bucket_size;
      std::fill(update.begin() + l_bucket, update.begin() + r_bucket + 1, b);
    }
  }

  int at(int i) {
    int bucket_index = i / bucket_size;
    return update[bucket_index] != no_update ? update[bucket_index] : buckets[bucket_index][i % bucket_size];
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
    l--; r--;
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
    std::cout << f.sum() - g.sum() << std::endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  solve();
  return 0;
}
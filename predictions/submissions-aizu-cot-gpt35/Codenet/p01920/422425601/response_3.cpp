#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<vector<int>> buckets;
  vector<int> update, bucket_sum;
  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num);
    update.resize(bucket_num, 2);
    bucket_sum.resize(bucket_num, 0);
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
    while (l % bucket_size != 0 && l <= r) {
      int bucket_index = l / bucket_size;
      if (update[bucket_index] != 2) {
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
      if (update[bucket_index] != 2) {
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
    for (int i = l / bucket_size; i <= r / bucket_size; ++i)
      update[i] = b;
  }
  int at(int i) {
    int bucket_index = i / bucket_size;
    if (update[bucket_index] != 2)
      return update[bucket_index];
    else
      return buckets[bucket_index][i % bucket_size];
  }
};

void solve() {
  int n, q;
  string s;
  scanf("%d", &n);
  cin >> s;
  scanf("%d", &q);
  vector<int> x1;
  for (int i = 0; i < n; i++)
    x1.push_back(s[i] - '0');
  sqrt_decomp f(x1);
  int sum = f.sum();
  for (int i = 0; i < q; i++) {
    int l, r, b;
    scanf("%d %d %d", &l, &r, &b);
    l--;
    r--;
    f.query(l, r, b);
    if (b == 0)
      sum -= f.at(l - 1);
    else {
      int l_ = l, r_ = r - 1;
      if (0 <= l - 1 and f.at(l - 1))
        --l_;
      if (r + 1 < n and f.at(r + 1))
        ++r_;
      sum += r_ - l_ + 1;
    }
    printf("%d\n", sum);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}